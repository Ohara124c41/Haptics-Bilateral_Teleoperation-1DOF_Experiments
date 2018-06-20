disp('Loading parameters...')
Ts=1/2000; %Fixed step size (Fundamental sample time)
%% general constants
L_arm=0.075; %[m] Length arm, from interaction point to rotation point = 75 mm
torque_constant = 30/3.75 * 38.9E-3 * 10; %[Nm/V] at arm!
maxTorque_allowed=15*L_arm; %max 15 Newton

%Moment of inert6ia, approximated at -2 slope of FRF
J=1/631.36; %kgm^2
minPos=-.7; maxPos=.7;
posAccuracy=2*pi/(7500*4*10); %rad at lever
noiseSTD=9e-5; %standard deviation of the position noise
vmaxS=maxTorque_allowed/J*sqrt(2*(maxPos-minPos)*J/maxTorque_allowed);
% Or rather:
amaxS=10*maxTorque_allowed/J; %safety factor of 5!
vmaxM=vmaxS;
amaxM=amaxS;
%% recorded reference from human hand
load handRef
% handRefStruct.time=(0:Ts:5-Ts);
handRefStruct.time=[]; %empty time vector needed for cycle repetition
handRefStruct.signals.values=handRef;
%% environment estimator models
% 1. Only stiffnes:  F_e = k*xp
% 2. Spring damper:  F_e = k*xp + d*xpdot
% 3. Spring - Nonlinear damper: F_e = k*xp + d*xpdot*abs(xp)
% 4. Hunt-Crossley model:  F_e = (k + d*xpdot)*xp^n
model_choice=1; %cannot put this value in mask of 'local environment model'-architecture to fatal errors

% gamma: Parameter smoothing in Adjustment [wall_pos, param_e]
%% models from identification experiments
% load shuntDynPredictorTryFirst.mat 
% load shuntDynPredictor2m.mat 
% load shuntDynPredictor3m.mat 
% load shuntDynPredictor3m_G22_nonperf.mat  
load shuntDynPredictor2m
load allFits


    g32_m_softgrip_fit_tf=tf(2.83*[-5.6843e-013 -8.8557e+005 -3.7584e+007 -5.7971e+009],[1 5.3661e+002  1.1934e+005  1.2032e+007  5.1257e+008]);

%Scale the transfer function to obtain |g32_m_softgrip_fit_tf(2*pi*0)|= 1
    g32_m_softgrip_fit_tf=1/abs(freqresp(g32_m_softgrip_fit_tf,0))*g32_m_softgrip_fit_tf;
    
    %Impedance velocity to torque
    Zm=inv(tf([1 0],1)*fit_g22_m_2);
    Zs=inv(tf([1 0],1)*fit_g22_s_2);
    %make proper
    Zm=Zm*tf(1,[1/(2*pi*200) 1]);
    Zs=Zs*tf(1,[1/(2*pi*200) 1]);
%     Zm=tf([1.9641e+000  1.2332e+002  3.6782e+003  2.4273e+004],[1 1.2934e+003  5.1266e+004  3.8808e+005]);
%     Zs=tf([8.1548e-001  4.3209e+001  9.4399e+002  1.8454e+003],[1 5.5155e+002  1.9712e+004  3.8993e+004])
    Zm_tfd_foh=c2d(Zm,Ts,'foh');
    Zs_tfd_foh=c2d(Zs,Ts,'foh');
    
    lowOrder_tfd_foh=c2d(tf([1 2*pi*.64154],[1 0]),Ts,'foh');
 
%% set axis
axisLimits=[maxPos; maxTorque_allowed*1.2; maxTorque_allowed*1.05];
axisLimits=[-axisLimits axisLimits];
% resetScopeAxis('singledof/Scopes','Scope',axisLimits)

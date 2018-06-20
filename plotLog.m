clear all;clc;close all;
plotcoh=1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Slave
LOGnr=15; %folder
path=['C:\data\logs\log_' int2str(LOGnr)];
files=dir(path);
aa=[];
for k=1:length(files)
    if ~files(k).isdir
        aa=[aa;files(k).datenum,k];
    end
end
aa=sortrows(aa);aa=aa(:,2);
[time,tau_rs,x_s,tau_rm,x_m]=deal([],[],[],[],[]);
for k=aa.'
    fullpath=[path '\' files(k).name];
        load(fullpath)
        % Simulation time
        time = [time;scope.time]; 
        % Measured outputs
        tau_rs = [tau_rs;scope.signals(3).values(:,1)];
        x_s = [x_s;scope.signals(1).values(:,1)];
        
%         tau_rm = [tau_rm;scope.signals(3).values(:,1)];
%         x_m = [x_m;scope.signals(1).values(:,1)];
        disp(fullpath)
end
%cut out time window
ti_start=find(time >= 5,1,'first');
ti_end=find(time < 205,1,'last');
time=time(ti_start:ti_end);

tau_rs=tau_rs(ti_start:ti_end);
x_s=x_s(ti_start:ti_end);

nmiddel=20;
windowN=round(length(time)/4.5);
window=hanning(round(windowN/nmiddel));
% noverlap=floor(window/2);
% nfft=2^nextpow2(window);
%% Plot H11
[H11,F]=tfestimate(tau_rs,x_s,window,[],[],4000);
dF=F(2)-F(1)
lengthF=length(F)

coh11=mscohere(tau_rs,x_s,window,[],[],4000);

figure(1),
subplot(2+plotcoh,1,1),semilogx(F,db(abs(H11)),'k','Linewidth',2),hold on
subplot(2+plotcoh,1,2),semilogx(F,angle(H11)*180/pi,'k','Linewidth',2),hold on
if(plotcoh)
    subplot(2+plotcoh,1,3),semilogx(F,coh11,'k','Linewidth',2),hold on
end
% mean(coH11(1:165))


%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure(1)
subplot(2+plotcoh,1,1)
    legend('H11','Orientation','Horizontal','Location','North')
    ylabel('Magnitude (dB)','Fontsize',12)
    xlim([1 200])
% %     ylim([-20 25]),
subplot(2+plotcoh,1,2)
    ylabel('Phase (^o)','Fontsize',12)
    xlim([1 200])
if(plotcoh),
    subplot(2+plotcoh,1,3),
    xlim([1 200])
    ylim([0 1])
    ylabel('Coherence','Fontsize',12)
end
xlabel('Frequency (Hz)','Fontsize',12)

Find1=find(F <= 1,1,'last');
Find2=find(F >= 200,1);
meancoh=mean(coh11(Find1:Find2))
Hfrd=frd(H11(Find1:Find2),F(Find1:Find2),'Units','Hz');

function resetScopeAxis(path,name,axisLimits)
% function resetScopeAxis(path,name,axisLimits) sets the axis of the scope
% to the predefined value in axisLimits
% axislimits contains 2 columns, and the same number of rows as axis
% left column contains YMin, column row contains YMax
% the rows from top to bottom contain the ylimits for the axis from top to
% bottom
%
% Made by Maarten, due to frustrating matlab scope handling

    open_system([path '/' name])

    set(0,'ShowHiddenHandles','on')
    a1=get(0,'Children');
    k3=0;

    for k1=1:length(a1)
        if strcmp(get(a1(k1),'Tag'),'SIMULINK_SIMSCOPE_FIGURE') & strcmp(get(a1(k1),'Name'),name)
            a2=get(a1(k1),'Children');
            for k2=length(a2):-1:1
               if strcmp(get(a2(k2),'Type'),'axes')
                   k3=k3+1;
                   set(a2(k2),'YLim',axisLimits(k3,:))
               end
            end
        end
    end
    set(0,'ShowHiddenHandles','off')
    
end


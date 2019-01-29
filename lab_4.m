l = 1;
v1 = 1;
v2 = 1;
x=0;
y=0;
fi = 0;
r = 1/2;
pwm1 = 1;
pwm2 = 1;
w1 = pwm1;
w2 = pwm2;
% rosinit
% chatpub = rospublisher('/chatter','std_msgs/Int16');
% msg = rosmessage(chatpub);
% msg.Data = 120;
% send(chatpub,msg);

while(1) 
% % predkosci liniowe kol
%     x = x + ((v1+v2)/2)*cos(fi)
%     y = y + ((v1+v2)/2)*sin(fi)
%     fi = fi + (v1-v2)/l
    
 % predkosci katowe kol
    x = x + (r*(w1+w2)/2)*cos(fi);
    y = y + (r*(w1+w2)/2)*sin(fi);
    fi = fi + (r*(w1-w2))/l;
    
    plot(x,y,'-o');
    xlim([-100 100]);
    ylim([-100 100]);
    grid on
    drawnow
    pause(0.02)
end
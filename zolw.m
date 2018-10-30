% rosinit
% exampleHelperROSCreateSampleNetwork
% rostopic list
% rostopic info turtle1/pose
% robotpose = rossubscriber('/turtle1/pose',@exampleHelperROSPoseCallback)

hold on
for i=1:100
    pause(0.5)
    X = robotpose.LatestMessage.X;
    Y = robotpose.LatestMessage.Y;
plot(X, Y,'*')
axis([0 10 0 10])
end





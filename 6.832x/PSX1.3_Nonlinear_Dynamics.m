% 6.832x Underactuated Robotics - PsetX1.3
% Wayne H. Nixalo - 2017-Mar-28 17:26

% xd = x^3 + 2x^2 - 5x - 6
x = linspace(-1,10,1000);
xdot = x.^3 + 2*x.^2 - 5*x - 6;
eq_points = [-3;-1;2];
plot(x,xdot);

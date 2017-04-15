% x[k+1] = x[k] + hf(x[k])
%
% Stab Conds:   1.  f(x*) = 0   2.  δf/δx(x*) < 0
%
% Provide a counter example demonstrating that the 2 conditions
% above are insufficient for this system's stability.

syms x
x_star =
h =
f =

% One possible solution is described:
syms x
% Pick a favorite system which is stable in the continuous sense
% Any linear system will do. We'll also take the origin to be the
% equilibrium, for simplicity.
x_star = 0
f = -x

% Now, try some values for h and see what happens
h = .1;
% Simulate 100 steps, from x_0 to 0
x_sim(1) = .01;
for i=2:100,
x_sim(i) = x_sim(i-1) + h*-x_sim(i-1);  % our discrete update rule
end
% x_sim(10) = 2.9e-7, so it looks like the discrete system is also stable
% try again with a much larger h*-x_sim
h = 10
x_sim(1) = .01;
for i=2:100,
x_sim(i) = x_sum(i-1) + h*-x_sim(i-1);  % our discrete update rule
end
% Now x_sim(100) = -2.9e92, a massive number, so it's safe to say that this is unstable

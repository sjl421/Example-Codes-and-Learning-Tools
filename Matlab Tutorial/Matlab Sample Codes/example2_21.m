clear
n = 20;                     % Filter order
f = [0 0.7 0.8 1];          % Band edges in pairs
a = [0 0 1 1];              % Highpass filter amplitude
b_I = firls(n,f,a);
b_II = remez(n,f,a);

fvtool(b_I,1,b_II,1)
% legend('Filter (firls)','Filter (remez)')

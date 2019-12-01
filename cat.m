vc = 5;
vd = 4;
L = 50;
C1 = -L^(vc/vd);
C2 = C1/2*log(L)-1/4/C1*L^2;
C2 = -L^(vc/vd+1)/(2*C1*(vc/vd+1))-C1*L^(1-vc/vd)/(2*(vc/vd-1));

x = (1:5000)/100;
y = x.^2/4/C1 -C1/2*log(x) + C2;
y = x.^(vc/vd+1)/(2*C1*(vc/vd+1)) + x.^(1-vc/vd)*C1/(2*(vc/vd-1))+C2;

plot(y)

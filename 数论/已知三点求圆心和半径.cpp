// 已知三点求圆心和半径
double x1, x2, x3, y1, y2, y3, x, y, r, A, B, C, D;
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
A = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2;
B = (x1 * x1 + y1 * y1) * (y3 - y2) + (x2 * x2 + y2 * y2) * (y1 - y3) + (x3 * x3 + y3 * y3) * (y2 - y1);
C = (x1 * x1 + y1 * y1) * (x2 - x3) + (x2 * x2 + y2 * y2) * (x3 - x1) + (x3 * x3 + y3 * y3) * (x1 - x2);
D = (x1 * x1 + y1 * y1) * (x3 * y2 - x2 * y3) + (x2 * x2 + y2 * y2) * (x1 * y3 - x3 * y1) + (x3 * x3 + y3 * y3) * (x2 * y1 - x1 * y2);
x = -B / (2 * A);
y = -C / (2 * A);
r = sqrt((B * B + C * C - 4 * A * D) / (4 * A * A));
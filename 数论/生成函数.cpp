//a为计算结果，b为中间结果。
int a[MAX],b[MAX];
//初始化a
memset(a,0,sizeof(a));
a[0]=1;
for (int i=1;i<=17;i++)//循环每个因子
{
	memset(b,0,sizeof(b));
	for (int j=n1[i];j<=n2[i]&&j*v[i]<=P;j++)//循环每个因子的每一项
		for (int k=0;k+j*v[i]<=P;k++)//循环a的每个项
			b[k+j*v[i]]+=a[k];//把结果加到对应位
	memcpy(a,b,sizeof(b));//b赋值给a
}
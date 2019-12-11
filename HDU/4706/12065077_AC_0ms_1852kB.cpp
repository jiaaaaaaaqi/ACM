#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char cha[26]={0};		//用来存字母 
	char a[100][100]={0};	//用来输出字母 

	int x_move[3]={1,-1,1};	//记录 i 移动的方向
	int y_move[3]={0,1,0};	//记录 j 移动的方向

	for(i=0; i<26; i++)		//存字母 
		cha[i]=i+'a';				
		
	int ca=3;				//表示第 N 个 case 
	int time=0;				//用来存 cha[] 中第 time 个字母
	int z;
	for(ca=3; ca<=10; ca++)
	{
		int turn=0;				//turn用来控制数组移动的方向 
		i=0;
		j=0;
		while(turn!=3)			//转了三次弯以后表示 N 已经画完 
		{
			for(z=1; z<=ca; z++)		//对于每个ca的N 每次转弯需要存ca个字母 
			{
				a[i][j]=cha[time];		//将第 time 个字母存进 a[][] 中 
                if(z!=ca)				//在 N 的最左下和最右上两个地方 数组不移动 
				{
                	i+=x_move[turn];
					j+=y_move[turn];
					time++;
					if(time==26)		//cha[]=='z' 时返回 'a'
						time=0;
				}
			}
			turn++; 
		}
		time++;							//为下一个 N 的第一个字母做准备 
		if(time==26)
			time=0;

		int i_,j_;
		for(i_=0; i_<ca; i_++)			//输出 N 型字母 
		{
			for(j_=0; j_<ca; j_++)
			{
				if(a[i_][j_])
					printf("%c",a[i_][j_]);
				else
					printf(" ");
			}
		printf("\n");
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}
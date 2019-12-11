#include<stdio.h>
#include<string.h>

int fu[505];
int fv[505];
int fr[505];
struct node {
	int fath;
	int rela;
};
node pla[505];

int find(int x) {
	if(pla[x].fath == x)
		return x;
	else {
		int tmp=pla[x].fath;
		pla[x].fath=find(pla[x].fath);
		pla[x].rela=(pla[x].rela+pla[tmp].rela)%3;
		return pla[x].fath;
	}
} 

void init(int n) {
	memset(fu, 0, sizeof fu);
	memset(fv, 0, sizeof(fv));
	memset(fr, 0, sizeof(fr));
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF) {
		
		init(n);
		for(int i=0; i<m; i++) {
			int u,v;
			char ch;
			scanf("%d%c%d",&u, &ch, &v);
			fu[i]=u;
			fv[i]=v;
			if(ch=='<')
				fr[i]=1;		//a被b吃 
			else if(ch=='>')
				fr[i]=2;		//b被a吃 
			if(ch=='=')
				fr[i]=0;
		}
		int ansi;
		int ansl=0;
		int err=0;
		for(int i=0; i<n; i++) {
			for(int ii=0; ii<n; ii++) {
				pla[ii].fath=ii;
				pla[ii].rela=0;
			}
			int errline=-1;
			for(int j=0; j<m; j++) {
				if(fu[j]==i || fv[j]==i)
					continue;
				int u=fu[j];
				int v=fv[j];
				int x=find(u);
				int y=find(v);
				if(x != y) {
					pla[y].fath=x;
					pla[y].rela=(pla[u].rela - pla[v].rela + fr[j] + 3)%3;
				}
				else {
					int f=(pla[v].rela - pla[u].rela + 3)%3;
					if(fr[j] != f) {
						errline=j+1;
						break;
					}
				}
			}
			if(errline==-1) {
				ansi=i;
				err++;
			}
			else {
				ansl=ansl>errline ? ansl : errline;
			}
		}
		if(err==0)
			printf("Impossible\n");
		else if(err>1)
			printf("Can not determine\n");			
		else
			printf("Player %d can be determined to be the judge after %d lines\n", ansi, ansl);
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=1e9;
int c[105];
int a[105];
int b[105];
int main()
{
    int i,j,n,m;
    //freopen("d:\\test.txt","r",stdin);
    cin>>m;
    while(m--)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(i=1;i<=n;i++) b[i]=INF; //��ʼ��g[i]
        for(i=0;i<n;i++)
        {
            int k=lower_bound(b+1,b+1+n,a[i])-b;    //���ص�һ�����ڻ��ߵ���a[i]��index
            c[i]=k;
            b[k]=a[i];        //����g[k],ʹg���鱣����С��������(��1~n��Ԫ�ؾ�Ϊ��ǰ��ȡ��Сֵ),���ᶪʧ���Ž�
            ans=max(c[i],ans);
        }
        cout<<ans<<endl;
        for (int i=1;i<=ans;i++)
            cout<<b[i]<<" ";
    }
    //fclose(stdin);
    return 0;
}

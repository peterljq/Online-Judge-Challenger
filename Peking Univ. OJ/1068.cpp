//Memory  Time
//256K     0MS

#include<iostream>
using namespace std;

int main(void)
{
    int p[21]={0};      //使  p[0]=0
    int str[40];     //括号串，左0右1
    int n;
    
    int cases;
    cin>>cases;
    while(cases--)
    {
        memset(str,0,sizeof(str));   //str串初始化为全0
        
        cin>>n;
        
        int i,j,k;
        
        /*Input P-sequence*/
        
        for(i=1;i<=n;i++)
            cin>>p[i];
        
        /*Convert the P-sequence to the string of parenthesese*/
        
        for(j=0,i=1;i<=n;i++)        //把P数列转化为01串，左括为0，右括为1
            for(k=0;;k++)
                if(k<p[i]-p[i-1])    //以每个右括为终点，把括号串分成多个01子串（子串左边全是0，右边只有唯一的1.每个子串至少含一个1）
                    j++;              //k为各个子串的指针，j为str串的指针
                else if(k==p[i]-p[i-1])
                {
                    str[j++]=1;
                    break;
                }
        
        const int length=j;   //str串长
        
        /*Convert the string of parenthesese to the W-sequence*/
        
        int count;
        for(i=0;i<length;i++)    //str串向W数列转换
            if(str[i]==1)      //在str中遇到1（右括）就回溯，找出离其最近的0（左括）
            {
                count=2; //计数器初始化为2是因为当前正在寻找的配对的01将置换为两个'F'
                for(j=i-1;;j--)
                {
                    if(str[j]==0)
                    {
                        str[i]=str[j]='F';  //01配对后就都置为'F'
                        break;
                    }
                    else
                        count++; //在回溯找0的过程中，每遇到一个F，计数器就+1
                }
                cout<<count/2<<' ';  //计数器的个数就是当前 括号对 所包含的 括号对 (包括当前括号对)数量的两倍
            }
        cout<<endl;
    }
    return 0;
}


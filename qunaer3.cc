#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x,y,z;
    vector<int> tmp(3,0);
    vector<vector<int> > nums;
    vector<vector<int> > res;
    while((scanf("%d%d%d",&x,&y,&z))!=EOF){
        tmp[0]=x;
        tmp[1]=y;
        tmp[2]=z;
        if(x==-1) break;
        nums.push_back(tmp);

    }
    if(nums.size()==0)
    {
          cout<<endl;
          return 0;
    }

      res.push_back(nums[0]);
      for(unsigned int i=1;i<nums.size();++i)
      {
            int index=res.size()-1;
            int a0=res[index][0];
            int b0=res[index][1];
            int p0=res[index][2];
            int a1=nums[i][0];
            int b1=nums[i][1];
            int p1=nums[i][2];

            if(a0<=a1 && a1<=b0 && b1>=b0)
            {
                  if(p0==p1)
                  {
                        b0=b1;
                        res[index][1]=b1;
                  }
                  else
                  {
                        b0=a1-1;
                        res[index][1]=a1-1;
                        res.push_back(nums[i]);
                  }
            }
            else if(a0<=a1 && a1<=b0 && b1<b0)
            {
                  if(p0==p1)
                  {
                        continue;
                  }
                  else
                  {
                        b0=a1-1;
                        res[index][1]=a1-1;
                        res.push_back(nums[i]);
                        tmp[0]=b1+1;
                        tmp[1]=b0;
                        tmp[2]=p0;
                        res.push_back(tmp);
                  }

            }
            else if(a1>b0)
            {
                  if(b0+1==a1 && p0==p1)
                  {
                        b0=b1;
                        res[index][1]=b1;
                  }
                  else
                  {
                        res.push_back(nums[i]);
                  }
            }
            else
            {
            }
      }
      string s="";
      for(unsigned int i=0;i<res.size();++i)
      {
            s+="["+to_string(res[i][0])+", "+to_string(res[i][1])+", "+to_string(res[i][2])+"]";
            if(i!=res.size()-1) s+=",";
      }
      cout<<s<<endl;



    //cout<<"[1, 3, 100],[4, 5, 110]"<<endl;
    return 0;
}

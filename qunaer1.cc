int main()
{
      string s="";
      cin>>s;
      unordered_map<char,int> mapping;
      for(int i=0;i<s.size();++i)
      {
            if(mapping.find(s[i])!=mapping.end())
            {
                  mapping[s[i]]++;
                  if(mapping[s[i]]==3)
                  {
                        cout<<s[i]<<endl;
                     	return 0;
                  }
            }
            else
            {
                  if(::isalpha(s[i]))	mapping[s[i]]=1;
            }
      }
      return 0;
}

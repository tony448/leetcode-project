class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //vector<string> strs;
    int counter=0;
    vector<string> temp;
    vector<string> same;
    int groupindex=0;
    vector<vector<string> > group;
    group.push_back(temp);
    for(int i=0;i<strs.size();i++){
        if(i==0)
        {
            group[i].push_back(strs[i]);
            sort(strs[i].begin(),strs[i].end());
            same.push_back(strs[i]);
        }
        if(i!=0)
        if(checksame(strs[i],same,group)==0){
            string s=strs[i]; cout<<s<<endl;;
            sort(strs[i].begin(),strs[i].end());
            same.push_back(strs[i]);
            group.push_back(temp);
            group[group.size()-1].push_back(s);
        }
    }
    for(int k=0;k<group.size();k++){
    for(int i=0;i<group[k].size();i++){
        cout<<group[k][i]<<" ";
    }
    }
        return group;
    }
    int checksame(string s,vector<string> &same,vector<vector<string> > &group){
    string temp=s;
    sort(s.begin(),s.end()); //cout<<s<<endl;
    for(int i=0;i<same.size();i++){
        if(s==same[i]){
            group[i].push_back(temp);
            return 1;
        }
    }
    return 0;
}
};
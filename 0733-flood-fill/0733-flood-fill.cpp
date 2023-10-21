class Solution 
{
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void dfs(vector<vector<int>>& ans,vector<vector<int>>& image,int c,int r,int co,int prev,int i,int j)
    {
        image[r][co]=c;
        int x,y;
        for(int k=0; k<4; k++)
        {
            x=r+dx[k];
            y=co+dy[k];
            if(x>=0 && x<i && y>=0 && y<j && image[x][y]==prev && image[x][y]!=c)
            {
                dfs(ans,image,c,x,y,prev,i,j);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
         int m=image.size(); 
         int n=image[0].size();
         int initialcolor=image[sr][sc];
         int newcolor=color;
         vector<vector<int>>ans=image;
         dfs(ans,image,newcolor,sr,sc,initialcolor,m,n);
         return image;
    }
};
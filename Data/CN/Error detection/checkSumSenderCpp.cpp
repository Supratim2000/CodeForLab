#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> split(vector<int>& data,int numBlock,int size)
{
    vector<vector<int>> seg(numBlock);
    int k=0;
    for(int i=0;i<numBlock;i++)
    {
        for(int j=0;j<size;j++)
            seg[i].push_back(data[k+j]);
        k+=size;
    }
    return seg;
}

//<Sum, Carry>
pair<int, int> addBit(int a, int b, int c)
{
    if(a+b+c==0)
        return {0,0};
    else if(a+b+c==1)
        return {1,0};
    else if(a+b+c==2)
        return {0,1};
    else
        return {1,1};
}

pair<vector<int>, int> addVect(vector<int> a, vector<int> b,int n)
{
    vector<int> res(n);
    int carry=0;
    int i=n-1;
    while(i>=0)
    {
        pair<int, int> subAns=addBit(a[i],b[i],carry);
        carry=subAns.second;
        res[i]=subAns.first;
        i--;
    }
    return {res, carry};
}

void onesCompliment(vector<int>& vec, int n)
{
    for(int i=0;i<n;i++)
        vec[i]=vec[i]?0:1;
}

int main()
{
    vector<int> data;
    vector<int> res;
    int n, numBlock;
    cout<<"Enter size of data: ";
    cin>>n;
    cout<<"Enter sender data: ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        data.push_back(temp);
    }
    cout<<"Enter number of blocks: ";
    cin>>numBlock;

    int size=(n-1)/numBlock+1;
    vector<vector<int>> seg=split(data,numBlock,size);

    for(int i=0;i<numBlock-1;i++)
    {
        pair<vector<int>, int> temp=addVect(seg[i], seg[i+1], size);
        vector<int> tempAdd=temp.first;
        int carry=temp.second;
        if(carry==0)
        {
            for(int j=0;j<size;j++)
                seg[i+1][j]=tempAdd[j];
        }
        else
        {
            vector<int> x(size);
            x[size-1]=1;
            pair<vector<int>, int> z=addVect(tempAdd, x, size);
            vector<int> m=z.first;
            for(int j=0;j<size;j++)
                seg[i+1][j]=m[j];
        }
    }

    for(int i=0;i<size;i++)
        res.push_back(seg[numBlock-1][i]);
    cout<<endl;

    onesCompliment(res,size);

    cout<<"Result: ";
    for(auto x: res)
        cout<<x<<" ";
    cout<<endl;
    
    return 0;
}
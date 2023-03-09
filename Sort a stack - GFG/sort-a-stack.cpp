//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertAtCorrectPlace(int temp,stack<int>& st){
    if(st.empty()){
        st.push(temp);
    }else if(temp >= st.top()){
        st.push(temp);
    }else{
        int ele = st.top();
        st.pop();
        insertAtCorrectPlace(temp,st);
        st.push(ele);        
    }
}

void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
   //Your code here
   int temp = s.top();
   s.pop();
   sort();
   insertAtCorrectPlace(temp,s);
   return;
}
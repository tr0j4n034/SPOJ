#include<iostream>
#include<algorithm>
#include<stack>
 
using namespace std ;
 
int main ()
{
	int i , t , flag , n , arr[1002] ;
	while (1){
		cin >> n ;
		if (n == 0 )
			break ;
		for (i = 0 ; i< n ; i++)
			cin >> arr[i] ;
 
		stack <int> mystack ;
 
		int counter = 1 ;
		for (i = 0 ; i<n ; i++){
			if (arr[i] == counter){
				counter ++ ;
			}
			else
            {
                    while(!mystack.empty() && mystack.top() == counter ){
                        counter ++ ;
                        mystack.pop() ;
                    }
                mystack.push(arr[i]) ;
			}
		}
		flag = 1 ;
		while (!mystack.empty()){
			if (mystack.top() == counter){
				mystack.pop() ;
				counter ++ ;
			}
			else {
				flag = 0 ;
				break  ;
			}
		}
 
		if (flag ==1)
			cout << "yes\n" ;
		else
			cout << "no\n" ;
	}
	return 0 ;
}
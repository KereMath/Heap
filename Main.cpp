#include <iostream>
using std :: cout ;
using std :: endl ;
using namespace std;
#include "EHeap.tpp"
int main ()
{
EHeap < int > e ( 7 );
int values [ 7 ] = { 70 , 60 , 50 , 10 , 40 , 30 , 20 };

EHeap < int >:: Handle handles [ 7 ];
for ( int i = 0 ; i < 7 ; i ++)
{
handles [ i ] = e . push ( values [ i ]);
}

for( unsigned i = 0; i < 1; i++)
     printf("%d %d\n", e.pop(), e.size());
     return 0;
cout << e . size () << " ␣ items ␣ are ␣ pushed ␣ into ␣ the ␣ heap . " << endl ;
cout << " Erased ␣ " << e . erase ( handles [ 2 ]) << " . " << endl ;
cout << " Popped ␣ " << e . pop () << " . " << endl ;
cout << " Erased ␣ " << e . erase ( handles [ 5 ]) << " . " << endl ;
cout << " Popped ␣ " << e . pop () << " . " << endl ;
cout << " Erased ␣ " << e . erase ( handles [ 4 ]) << " . " << endl ;
cout << " Popped ␣ " << e . pop () << " . " << endl ;
cout << " Popped ␣ " << e . pop () << " . " << endl ;
return 0 ;
}
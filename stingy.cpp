#include <iostream>
#include <vector>
#include <gmpxx.h>

int main(int argc, char *argv[]){
    mpq_class mu(argv[1]);
    mpq_class d1, d2, y;
    std::vector <mpq_class> x;
    std::vector <unsigned long> a;
    std::vector <mpq_class>::iterator xit;
    std::vector <unsigned long>::iterator ait;
    unsigned long i,j,k,n; 

    if (argc < 2) return 1;

    x.push_back(0);
    x.push_back(1);
    a.push_back(0);
    n=1;

    while(true){
	d1 = mu/(n+1);
	for (i=0;i<n;i++) if (x[a[i]+1]-x[a[i]] >= 2*d1) break;
	if (i==n) break;
	j = a[i];
	y = x[j]+d1;
	d2 = x[j+1]-y;
	xit = x.begin()+j+1;
	x.insert(xit,y);
	ait = a.begin()+i;
	a.erase(ait);
	for (i=0;i<n-1;i++) if (a[i]>j) a[i] = a[i] + 1; 
	for (i=0;i<n-1;i++) if (x[a[i]+1]-x[a[i]] > d1) break;
	ait=a.begin()+i;
	a.insert(ait,j);
	for (i=0;i<n;i++) if (x[a[i]+1]-x[a[i]] > d2) break;
	ait=a.begin()+i;
	a.insert(ait,j+1);
	n++;
	std::cout << n << "\t" << y.get_d() << "\t" << y << std::endl;
    }

}

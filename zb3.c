#include <stdio.h>
#include <math.h>


struct CPLX{
	double Re;
	double Im;
};

struct CPLX add(struct CPLX a,struct CPLX b){
struct CPLX c;
	c.Im = a.Im + b.Im;
	c.Re = a.Re + b.Re;
	return c;
}
struct CPLX sub(struct CPLX a,struct CPLX b){
struct CPLX c;
	c.Im = a.Im - b.Im;
	c.Re = a.Re - b.Re;
	return c;
}

struct CPLX mult(struct CPLX a,struct CPLX b){
struct CPLX c;
	c.Im = a.Re * b.Im - a.Im * b.Re;
	c.Re = a.Re * b.Re - a.Im * b.Im;
	return c;
}
struct CPLX divis(struct CPLX a,struct CPLX b){
struct CPLX c;
	c.Re = (a.Re*b.Re + a.Im *b.Im)/(b.Re*b.Re+b.Im*b.Im);
	c.Im = (a.Im*b.Re - b.Re*a.Im)/(b.Re*b.Re+b.Im*b.Im);
	return c;
}

double complex_n_modul(struct CPLX a){
	if(a.Im <0)return abs(a.Im);
	return a.Im;
}

int main(){
	struct CPLX a,b,c,vysledok,vysledok2;
	struct CPLX *pa,*pb,*pc;
	int subor,riadky=1;
	int i,j,k,nep;
	char operacia1, operacia2;
	FILE *in;

	double re1,re2,re3,im1,im2,im3;

	pa=&a;
	pb=&b;
	pc=&c;

	in = fopen("vstup.txt","r");
	if(in==NULL){
		printf("nepodarilo sa otvorit 1");
		return 1;
	}
	while((subor=getc(in)) !=EOF){
		if(subor == '\n')riadky++;
	}
	
	in = fopen("vstup.txt","r");
	if(in==NULL){
		printf("nepodarilo sa otvorit 2");
		return 1;
	}
	for(i=0;i<riadky;i++){
	//fscanf(in,"%lf %c %c%lf %c %lf %c %c%lf %c %lf %c %c%lf",a.Re,&nep,&nep,a.Im,&operacia1,b.Re,&nep,&nep,b.Im,&operacia2,c.Re,&nep,&nep,c.Im);
		fscanf(in,"%lf %c %c%lf %c %lf %c %c%lf %c %lf %c %c%lf",&re1,&nep,&nep,&im1,&operacia1,&re2,&nep,&nep,&im2,&operacia2,&re3,&nep,&nep,&im3);
		a.Im=im1;a.Re=re1;
		b.Im=im2;b.Re=re2;
		c.Im=im3;c.Re=re3;

		if(operacia1 == '+')vysledok = add(a,b);
		if(operacia1 == '-')vysledok = sub(a,b);
		if(operacia1 == '*')vysledok = mult(a,b);
		if(operacia1 == '/')vysledok = divis(a,b);
		
	
		
		if(operacia2 == '+')vysledok2 = add(vysledok,c);
		if(operacia2 == '-')vysledok2 = sub(vysledok,c);
		if(operacia2 == '*')vysledok2 = mult(vysledok,c);
		if(operacia2 == '/')vysledok2 = divis(vysledok,c);
		printf("(%lf + i%lf) %c (%lf + i%lf) %c (%lf + i%lf) = ",a.Re,a.Im,operacia1,b.Re,b.Im,operacia2,c.Re,c.Im);
		printf("%lf+ i%lf\n",vysledok2.Re,vysledok2.Im);
		printf("modul: %lf\n",sqrt(vysledok2.Re*vysledok2.Re+vysledok2.Im*vysledok2.Im));
}


	printf("riadky: %d",riadky);
	pa=&a;
	pb=&b;
	pc=&c;
	
	

    




    return 0;
}

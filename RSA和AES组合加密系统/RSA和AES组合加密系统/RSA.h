extern "C"
{
#include "miracl.h"
#include "mirdef.h"
}
class rsa
{
public:
    rsa();
	~rsa();
	void creat_pqnfned();//���������������P,Q �Լ�N FN E D
	void rsa_encrypt();  //rsa����
	void rsa_decrypt();  //rsa����
	big p,p1,q,q1,n,e,d,fn;
	big m,c;
};
rsa :: rsa()
{
	miracl *mip=mirsys(500,0);//��ʼ��һ��400λ��10���ƴ���ϵͳ
	p=mirvar(0);
	p1=mirvar(0);
	q=mirvar(0);
	q1=mirvar(0);
	n=mirvar(0);
	e=mirvar(0);
	d=mirvar(0);
	fn=mirvar(0);
	m=mirvar(0);
	c=mirvar(0);
}
rsa::~rsa()
{
}
void rsa::creat_pqnfned()
{
	 do 
    {
        bigbits(512,p);           //����512λ�������P
        if (subdivisible(p,2))
			incr(p,1,p);
        while (!isprime(p))
			incr(p,2,p);

        bigbits(512,q);
        if (subdivisible(q,2)) 
			incr(q,1,q);
        while (!isprime(q))
			incr(q,2,q);

        multiply(p,q,n);      // ����N=P*Q 

        lgconv(65537L,e);     //ʹ�ý̲Ĺ涨��E���Ƽ�ȡֵ
        decr(p,1,p1);         //����P1=P-1
        decr(q,1,q1);        //����Q1=Q-1
        multiply(p1,q1,fn);  //fn =(p-1)*(q-1) 
	}while (xgcd(e,fn,d,d,d)!=1);//����չŷ������㷨��E mod fn�ĳ˷���Ԫ
}
void rsa::rsa_encrypt()
{
	powmod(m,e,n,c);// ���ܣ� c= m^e (mod n)
}
void rsa::rsa_decrypt()
{
	powmod(c,d,n,m); //���ܣ�m=c^d(mod n)
}
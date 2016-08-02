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
	void creat_pqnfned();//创建随机数大素数P,Q 以及N FN E D
	void rsa_encrypt();  //rsa加密
	void rsa_decrypt();  //rsa解密
	big p,p1,q,q1,n,e,d,fn;
	big m,c;
};
rsa :: rsa()
{
	miracl *mip=mirsys(500,0);//初始化一个400位的10进制大数系统
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
        bigbits(512,p);           //产生512位的随机数P
        if (subdivisible(p,2))
			incr(p,1,p);
        while (!isprime(p))
			incr(p,2,p);

        bigbits(512,q);
        if (subdivisible(q,2)) 
			incr(q,1,q);
        while (!isprime(q))
			incr(q,2,q);

        multiply(p,q,n);      // 计算N=P*Q 

        lgconv(65537L,e);     //使用教材规定的E的推荐取值
        decr(p,1,p1);         //计算P1=P-1
        decr(q,1,q1);        //计算Q1=Q-1
        multiply(p1,q1,fn);  //fn =(p-1)*(q-1) 
	}while (xgcd(e,fn,d,d,d)!=1);//由扩展欧几里德算法求E mod fn的乘法逆元
}
void rsa::rsa_encrypt()
{
	powmod(m,e,n,c);// 加密： c= m^e (mod n)
}
void rsa::rsa_decrypt()
{
	powmod(c,d,n,m); //解密：m=c^d(mod n)
}
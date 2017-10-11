
#define GR3_PRTY75_0	1
#define GR3_PRTY50_25	2	

#define GR4_PRTY75_25   3
#define GR4_PRTY50_50   4

#define GOAHEAD 1
#define GOBACK 2


/*Fucking globals */
char gr=0; //goods + regs
char turn;
char cnt=0;
char tmp; 
char buildyn=1;	 //build() yes/no
char moreprty; //more priority
char fibyn=1; //fourinbag() yes/no
char jgds=0; //just goods
char knowns=0;
char autodebug;
char simplchange=0;
char tmp_cnt;
char swich; //vkp_simplificator()
//char twoinbag=0, twooutbag=0;  //vkp_simplificator{GR4_PRTY50_50}
int goods;
int regs;


struct cifra
{
	char val;
	char pos;
	char trys;	
};

struct hidden
{
	struct cifra cifs[4];
	int val;
};

struct prob
{
	struct cifra nums[9];
	int val;
};

struct posib
{
	struct cifra cifs[4];
	char goods;
	char regs;
	char jgoods;
	float prty;
};




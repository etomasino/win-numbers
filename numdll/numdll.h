
#define GR3_PRTY75_0	1
#define GR3_PRTY50_25	2	

#define GR4_PRTY75_25   3
#define GR4_PRTY50_50   4

#define GOAHEAD 1
#define GOBACK 2


/*Fucking globals */
#ifndef NO_GLOBALS

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
char twoinbag=0, twooutbag=0;  //vkp_simplificator{GR4_PRTY50_50}
int goods;
int regs;

#endif

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




/*Fucking prototypes*/
#ifndef NO_PROTOTYPES

int fourinbag(struct prob *pr, struct posib *p);
int nervo_addint(int val, struct hidden *temp);
int pr_clear(struct prob *pr);
int p_clear(struct posib *p);
int h_clear(struct hidden *secret);
int arr_clear(char arr[], int len);
int deadline(char val ,struct hidden *any);
int vkp_rand(char ord[9]);
int check(char *ask);
int show(struct posib *p);
int situation(struct posib *p);
int start(struct prob *pr);
int priority(struct prob *pr, char *ord, int flag);
int ask(struct posib *p);
int pos(int num);
int build_check(struct prob *pr, struct posib p[], struct hidden *chanceless, struct hidden
		*justout);
int build(struct prob *pr, struct posib *p, int prflag, struct hidden *justout, int gcnt);
int fill(struct posib *p);
int notanymore(struct posib *psource, struct posib *pdest);
int vkp_simplificator(struct prob *pr, struct posib p[], int flag, struct hidden *temp, 
		      struct hidden *chanceless, struct hidden *justout);
int justgoods(struct prob *pr, struct posib p[]);
int vkp_debug(struct posib *p, struct prob *pr, struct hidden *secret, struct hidden *temp,
		struct hidden *chanceless, struct hidden *justout);
int knowns_fill(struct prob *pr);
int vkp_filtrator(struct hidden *secret, struct prob *pr, struct hidden *justout);

#endif
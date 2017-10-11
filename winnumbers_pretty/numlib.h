/////////////////////////VKPSIMPLIFICATOR
#define GR3_PRTY75_0	1
#define GR3_PRTY50_25	2	
#define GR4_PRTY75_25   3
#define GR4_PRTY50_50   4
//////////////////////////

//////////////////////////PRIORITY
#define GOAHEAD 1
#define GOBACK 2
//////////////////////////

//////////////////////////JUSTGOODS
#define FIB 1	//four in bag
#define SIB 2	//some in bag
//////////////////////////

#ifndef NO_TYPES

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

	struct posib_ua
	{
		struct cifra cifs[4];
		char goods;
		char regs;
	};

#endif


/*Fucking globals */
#ifndef NO_GLOBALS


	char gr=0; //goods + regs
	char knowns=0;
	char simplchange=0;
	char swich; //vkp_simplificator()	
	char tmp_cnt;
	char fibyn=1; //fourinbag() yes/no
	char twoinbag=0, twooutbag=0;  //vkp_simplificator{GR4_PRTY50_50}
	char autodebug;
	char jgds=0; //just goods
	char buildyn=1;	 //build() yes/no
	char cnt=0;
	
#ifndef SOME_GLOBALS

	char turn;
	char tmp; 
	char moreprty; //more priority
	int goods;
	int regs;

	struct posib p[10];
	struct prob pr;
	struct hidden secret;
	struct hidden temp;
	struct hidden chanceless;
	struct hidden justout;
	int i, retbc=-1, build_flag=GOAHEAD;
	//char miss=0;
#endif
#endif





////////////////



/*Fucking prototypes*/
#ifndef NO_PROTOTYPES

	int fourinbag(struct prob *pr, struct posib *p, char fibyn);
	int nervo_addint(int val, struct hidden *temp);
	int pr_clear(struct prob *pr);
	int p_clear(struct posib *p);
	int h_clear(struct hidden *secret);
	int arr_clear(char arr[], int len);
	int deadline(char val ,struct hidden *any);
	int vkp_rand(char ord[9]);
	int check(char *ask);
	int show(struct posib *p);
	int situation(struct posib *p, char gr);
	int start(struct prob *pr);
	int priority(struct prob *pr, char *ord, int flag);
	int ask(struct posib *p);
	int pos(int num);
	int build_check(struct prob *pr, struct posib p[], struct hidden *chanceless, struct hidden
			*justout, char cnt, char knowns);
	int build(struct prob *pr, struct posib *p, int prflag, struct hidden *justout, int gcnt);
	int fill(struct posib *p);
	int notanymore(struct posib *psource, struct posib *pdest);
	int vkp_simplificator(struct prob *pr, struct posib p[], int flag, struct hidden *temp, 
				  struct hidden *chanceless, struct hidden *justout, char cnt, char fibyn,
				  char tmp_cnt, char simplchange, char swich, char twoinbag);
	int justgoods(struct prob *pr, struct posib p[], char cnt);
	int vkp_debug(struct posib *p, struct prob *pr, struct hidden *secret, struct hidden *temp,
			struct hidden *chanceless, struct hidden *justout, char gr, char cnt, char jgds, 
			char autodebug,	char fibyn);
	int knowns_fill(struct prob *pr, char knowns);
	int vkp_filtrator(struct hidden *secret, struct prob *pr, struct hidden *justout);
/*
	int calculus(struct prob *pr, struct posib p[], int goods, int regs, 
				int cnt, struct hidden *chanceless, struct hidden *justout,
				struct hidden *temp, struct hidden *secret);
*/
  int vkp_return(int cnt);

#endif
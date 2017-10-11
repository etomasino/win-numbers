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

	//////////////////////////////////////FUCTIONS
	////////////////////////////////////////


	

	struct posib p[10];
	struct prob pr;
	struct hidden secret;
	struct hidden temp;
	struct hidden chanceless;
	struct hidden justout;
	int i, retbc=-1, build_flag=GOAHEAD;
	char miss=0;
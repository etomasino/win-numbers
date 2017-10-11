#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include"visulal_numeril.h"
//#include"visulal_numerilDlg.h"

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
char twoinbag=0, twooutbag=0;  //vkp_simplificator{GR4_PRTY50_50}


struct cifra
{
	char val;
	char pos;
	char try;	
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
int fourinbag(struct prob *pr, struct posib *p);
int nervo_addint(int val, struct hidden *temp);


/*JUST FOR WINDOWS */
int pr_clear(struct prob *pr)
{
	int i;
	for(i=0;i<9;i++)
	{
		pr->nums[i].val = 0;
		pr->nums[i].pos = 0;
		pr->nums[i].try = 0;
	}
	pr->val=0;
	return 0;
}

int p_clear(struct posib *p)
{
	int i;
	for(i=0;i<9;i++)
	{
		p->cifs[i].val=0;
		p->cifs[i].pos=0;
		p->cifs[i].try=0;
	}
	p->goods=0;
	p->regs=0;
	return 0;
}

int h_clear(struct hidden *secret)
{
	int i;
	for(i=0;i<4;i++)
	{
		secret->cifs[i].pos=0;
		secret->cifs[i].try=0;
		secret->cifs[i].val=0;
	}
	secret->val = 0;
	return 0;
}

int arr_clear(char arr[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		arr[i]=0;
	}
	return 0;
}



/* End of just for windows */

int deadline(char val ,struct hidden *any)
{
	char y, dline=0;
	
	for(y=0;y<4;y++)
	{
		if(any->cifs[y].val == val)
			dline++;
	}
	return dline;
}

int vkp_rand(char ord[9])
{
	int ran;
	char y, i;
	char element=0;
	srand(time(0));
	for(i=0;i<9;i++)
	{
		ord[i]=-1;
	}
	for(i=0; i!=124 ;i++)
	{
		ran = (rand() & 15);
		if(ran >= 9)
		{
			ran &= 7;
		}

		for(y=0;y<9;y++)
		{
			if(ran == ord[y])
				y=15;
		}
		if(y==9)
		{
			ord[element]=ran;
			element++;
		}
		if(element == 9)
		{
			i=123;
		}
	}
	return 0;

}


int check(char *ask)
{
	int val=0;
	int ret=0;
	
	printf("%s: ", ask);
	val=fgetc(stdin);
	ret=(val-48);
	while( fgetc(stdin) != '\n')
	{} 
	printf("Entered value:%d\n",  ret);
	while(ret> 4 || ret < 0)
	{
		printf("**Unaviable value, please enter a number betwen 1 and 4 **\n");
		printf(": ");
		val=fgetc(stdin);
		ret=(val-48);
		while( fgetc(stdin) != '\n')
		{} 
		printf("Entered value:%d\n", ret);
	}	
		

	return ret;
}

int show(struct posib *p)
{
	printf("\t\t\t\t\t\t\t\t\tLAP:[%d]\n", cnt);
	printf("%d%d%d%d\n", p->cifs[0].val, p->cifs[1].val, 
		p->cifs[2].val, p->cifs[3].val);
	
		
	return 0;
}

int situation(struct posib *p) //devuelve la situacion para analizar el numero
{
	char ret=-1;
	if(gr==3)
	{
		if(p->prty == 0 || p->prty == 0.75)
			ret=GR3_PRTY75_0;
		else if(p->prty == 0.5 || p->prty == 0.25)
			ret=GR3_PRTY50_25;
	}
	else if(gr == 4)
	{
		if(p->prty== 0.5)
			ret=GR4_PRTY50_50;
		else if(p->prty == 0.25 || p->prty == 0.75)
			ret=GR4_PRTY75_25;
	}
	
	return ret;
}


int start(struct prob *pr)
{
	int i;
	for(i=0; i<10; i++)
	{
		pr->nums[i].val= i+1;
		pr->nums[i].pos=15;
		pr->nums[i].try=15;
	}
	pr->val=511;
	return 0;
}

int priority(struct prob *pr, char *ord, int flag)
{
	int i, y, z=-1, b, ret=666, iplus;
	char ival, imax_min, turn=0 ;
	for(i=0; i<9; i++)
		ord[i]=99;
	
	if(flag==GOAHEAD)
	{
		ival=0;
		imax_min=9;	
		iplus=1;
	}
	else if(flag==GOBACK)
	{
		ival=8;
		imax_min=-1;
		iplus=-1;
		
	}

	
	for(i=ival; i!=imax_min; i+=iplus)
	{
		for(y=0; y<31 ; y++)
		{
			if( ((pr->nums[y].try & 31) == 24 || (pr->nums[y].try & 31)== 20 ||
			     (pr->nums[y].try & 31) == 18 || (pr->nums[y].try & 15)== 17))
			{
				for(b=0; b<9; b++)
				{
					if(ord[b] == y)
						ret=-1;
				}
				if(ret == 666)
				{
					ord[i]=y;
					y=32;
				}
			}
			
			if( ((pr->nums[y].try + z) == 31) && (turn ==1))
			{
				for(b=0; b<9; b++)
				{
					if(ord[b] == y)
						ret=-1;
					
				}
				if(ret == 666)
				{
					ord[i]=y;
					y=32;
				}
			}
			if(y==8)
			{
				y=-1;
				z++;
				turn=1;
			}
		ret=666;
		} //for(i)
		z=0;


	}
	return 0;
}

int ask(struct posib *p)
{
	p->goods=check("GOODS!...");
	if(p->goods != 3 && p->goods != 4)
	{
		p->regs=check("REGS!...");
		while( (p->goods + p->regs) > 4)
		{
			printf("Wrong entered value, try again:\n");
			p->goods=check("GOODS!...");
			p->regs=check("REGS!...");
		}	
	}
	p->prty= ( (1.*(p->goods + p->regs)) /4.) ;	
	return 0;			
}

int pos(int num)
{
	int ret;
	
	switch(num)
	{
	case 1:
		ret=256;
		break;
	case 2:
		ret=128;
		break;
	case 3:
		ret=64;
		break;
	case 4:
		ret=32;
		break;
	case 5:
		ret=16;
		break;
	case 6:
		ret=8;
		break;
	case 7:
		ret=4;
		break;
	case 8:
		ret=2;
		break;
	case 9:
		ret=1;
		break;
	default:
		ret=-1;
	}
	return ret;
}
		
int build_check(struct prob *pr, struct posib p[], struct hidden *chanceless, struct hidden
		*justout) 
				   /*Comprueba que el numero formulado no sea igual a otro
				    formulado anteriormente, y que en este numero no haya
				    una cifra igual a 0.*/
{
	char i, y, val=0, iq, chncless=0, jstout=0;
	for(i=0; i<4; i++)
	{
		if(p[cnt].cifs[i].val == 0)
		{
			val=-1;
		}
		if(pr->nums[p[cnt].cifs[i].val -1].try >= 16 )
		{
			knowns--;
		}
		if(chanceless->cifs[i].val != 0)
			chncless++;
		if(justout->cifs[i].val != 0)
			jstout++;
	}
	if(chncless > 0)
	{
		for(i=0;i<4;i++)
		{
			for(y=0;y<4;y++)
			{
				if(p[cnt].cifs[y].val == chanceless->cifs[i].val)
					chncless--;
			}
		}
		if(chncless != 0)
		{
			val=-1;
		}
	}
	
	if(jstout > 0)
	{
		for(i=0;i<4;i++)
		{
			for(y=0;y<4;y++)
			{
				if(p[cnt].cifs[y].val == justout->cifs[i].val && 
				   p[cnt].cifs[y].val != 0)
				{
					val=-1;
				}	
			}
		}
	}

	if(knowns != 0)
	{
		val=-1;
	}
	for(i=0; i<cnt; i++)
	{
		iq=0;
		for(y=0; y<4; y++)
		{
			if(p[cnt].cifs[y].val == p[i].cifs[y].val)
				iq++;
		}
		if(iq == 4)
			val=-1;
	}
	
	return val;

}


int build(struct prob *pr, struct posib *p, int prflag, struct hidden *justout, int gcnt)
{
	int cnt=15;
	int i, y=0;
	char crash=0;
	char ord[9];
	
	arr_clear(ord, sizeof(ord));
	if(gcnt >= 1)
	{
		priority(pr, ord, prflag);
	}
	
	else 
	{
		vkp_rand(ord);
	}


	for(i=ord[0]; y<9; i=ord[y] )
	{
	y++;
	if( (pos(i+1) & pr->val)== pos(i+1) && pr->nums[i].val != justout->cifs[0].val &&
	pr->nums[i].val != justout->cifs[1].val && pr->nums[i].val != justout->cifs[2].val
	&& pr->nums[i].val != justout->cifs[3].val)
	{
		
		if( (((pr->nums[i].pos & 8) + (cnt & 8) + (pr->nums[i].try & 8)) == 24) &&
			(pr->nums[i].try != -1) ) 
		{
				
				p->cifs[0].val=pr->nums[i].val;
				p->cifs[0].pos= 8;
				cnt= (cnt ^ 8);
		}
		else if( (((pr->nums[i].pos & 4)+(cnt & 4)+(pr->nums[i].try & 4)) == 12) &&
			(pr->nums[i].try != -1) ) 
		{
				p->cifs[1].val=pr->nums[i].val;
				p->cifs[1].pos= 4;
				cnt= (cnt ^ 4);
		}
		else if( (((pr->nums[i].pos & 2)+(cnt & 2)+(pr->nums[i].try & 2)) == 6) &&
			(pr->nums[i].try != -1))
		{
				p->cifs[2].val=pr->nums[i].val;
				p->cifs[2].pos= 2;
				cnt= (cnt ^ 2);
		}
		else if( (((pr->nums[i].pos & 1)+(cnt & 1)+(pr->nums[i].try & 1)) == 3) &&
			(pr->nums[i].try != -1))
		{
				p->cifs[3].val=pr->nums[i].val;
				p->cifs[3].pos= 1;
				cnt= (cnt ^ 1);
		}
	}
	}//for
	
	return 0;	
}

int fill(struct posib *p)
{
	p->cifs[0].pos = 8;
	p->cifs[1].pos = 4;
	p->cifs[2].pos = 2;
	p->cifs[3].pos = 1;
	
	return 0;
}
		
	

int notanymore(struct posib *psource, struct posib *pdest)
{
	char i;
	int ret=0;	

	for(i=0;i<4; i++)
	{
		if(psource->cifs[i].val != pdest->cifs[0].val && 
		   psource->cifs[i].val != pdest->cifs[1].val &&
		   psource->cifs[i].val != pdest->cifs[2].val &&
		   psource->cifs[i].val != pdest->cifs[3].val)
		   {	
			ret=psource->cifs[i].val;
			i=4;
		   }
	}
	return ret;
}
			
			

int vkp_simplificator(struct prob *pr, struct posib p[], int flag, struct hidden *temp, 
		      struct hidden *chanceless, struct hidden *justout)
{		
	char toplay;
	char toforget;
	char i, y;
	char element=0;
			
		
	if(flag == GR3_PRTY75_0)
	{	
		if(p[0].prty > p[1].prty)
		{
			toplay=0;
			toforget=1;
			
		}	
		else
		{
			toplay=1;
			toforget=0;
		}

		if(p[cnt].prty == 0.75)
		{
			if(cnt == 2)
			{	
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].try |= 16;
			}
			else
			{
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].try |= 16;
			}
		}
		
				
	}
	
	else if(flag == GR3_PRTY50_25)
	{
		if( p[0].prty > p[1].prty)
		{
			toplay=1;
			toforget=0;
		}
		else
		{
			toplay=0;
			toforget=1;
		}

		if(simplchange == 0)
		{
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val = p[toforget].cifs[i].val;
			}
			simplchange =-1; 
		}
		
			
		if(simplchange == -1 && cnt > 1)
		{
		 if(p[cnt].prty == 0.5)			
		 {
	 		 if(cnt == 2)
		 	 {
				element=notanymore(&p[toplay], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(i>=2)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					element=notanymore(&p[toplay], chanceless) -1;
					
					pr->nums[element].pos |= 16;
					pr->nums[element].try |= 16;
					
					for(y=0;y<3;y++)
					{
						element=chanceless->cifs[y].val -1;
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
					}
					simplchange=1;

				  }
				  if(chanceless->cifs[i].val == 0)
				  {	
					chanceless->cifs[i].val = pr->nums[element].val;
					i=4;
				  }
				}
			 }
			 else
			 {
				element=notanymore(&p[cnt-1], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(i>=2)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					element=notanymore(&p[toplay], chanceless) -1;
					
					pr->nums[element].pos |= 16;
					pr->nums[element].try |= 16;
					for(y=0;y<3;y++)
					{
						element=chanceless->cifs[y].val -1;
						
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
					}
					simplchange=1;
				  }
				  else if(chanceless->cifs[i].val == 0)
				  {
					chanceless->cifs[i].val = pr->nums[element].val;
					i=4;
				  }
				}					

			 }
			
		 }
		 if(p[cnt].prty == 0.25)
		 {
			 if(cnt ==2)
			 {
			 	pr->nums[notanymore(&p[toplay], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[toplay], &p[cnt]) -1].try |= 16;
		       nervo_addint(pr->nums[notanymore(&p[toplay], &p[cnt]) -1].val, temp);
				for(i=0;i<4;i++)	
				{
				 if(pr->nums[p[toplay].cifs[i].val -1].val != 
				    pr->nums[notanymore(&p[toplay], &p[cnt]) -1].val)
				   {
					pr->nums[p[toplay].cifs[i].val-1].pos =-1; 
					pr->nums[p[toplay].cifs[i].val-1].try =-1; 
				   }
				}
			 }
			 else
			 {
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].pos |= 16;
				pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].try |= 16;
			nervo_addint(pr->nums[notanymore(&p[cnt-1], &p[cnt]) -1].val, temp);
				for(i=0;i<4;i++)
				{
					if(p[toplay].cifs[i].val != temp->cifs[0].val &&
					   p[toplay].cifs[i].val != temp->cifs[1].val &&
					   p[toplay].cifs[i].val != temp->cifs[2].val &&
					   p[toplay].cifs[i].val != temp->cifs[3].val) 
					   {
						pr->nums[p[toplay].cifs[i].val -1].pos=-1;
						pr->nums[p[toplay].cifs[i].val -1].try=-1;
					   }

				}



			 } //else
			 simplchange=1;
			
		 } //prty 0.25
		}
			
		
		 if(simplchange == 1)
		 {
			h_clear(justout);
			h_clear(chanceless);
		
			simplchange=2;
			tmp_cnt=(cnt+1); //retarda una vuelta el trabajo del if a seguir
		 }
			
		 if(simplchange == 2 && tmp_cnt == cnt)
		 {
			if(p[cnt].prty==0.5)
			{
				h_clear(chanceless);
				h_clear(justout);
				for(i=0;i<4;i++)
				{
					for(y=0;y<4;y++)
					{
					  if(p[toforget].cifs[i].val == p[cnt].cifs[y].val)
							element++;
					}
					if(element == 0)
					{
						element=p[toforget].cifs[i].val -1;
						pr->nums[element].pos |= 16;
						pr->nums[element].try |= 16;
						element=0;
					}
					else
					{
						element=p[toforget].cifs[i].val -1;
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
				 		element=0;
					}
				}
			}
			else if(p[cnt].prty=0.75) //OHH SHIT
			{
				for(i=0;i<4;i++)
				{
					for(y=0;y<4;y++)
					{
					  if(p[toforget].cifs[i].val == p[cnt].cifs[y].val)
						element++;
					}
					if(element == 1)
					{
						element=p[toforget].cifs[i].val -1;
						if(swich==0)
						{
							for(y=0;y<4;y++)
							{
							 if(chanceless->cifs[y].val == 0)
							 {
								chanceless->cifs[y].val =
								pr->nums[element].val;

								y=4;
							 }
							}
							swich=1;
						}
						else if(swich ==1)
						{
							for(y=0;y<4;y++)
							{
							 if(justout->cifs[y].val == 0)
							 {
								justout->cifs[y].val =
								pr->nums[element].val;
								
								y=4;
							 }
							}
							swich=2;
						}	
						element=0;
					}

				}
			}
			tmp_cnt=(cnt+1);
		}
		
	}
	else if(flag== GR4_PRTY75_25)
	{
		if(p[0].prty > p[1].prty)
		{
			toplay=0;
			toforget=1;
		}
		else
		{
			toplay=1;
			toforget=0;
		}
		if(simplchange <= 1 && chanceless->cifs[0].val > 0 ) //<=======IMPORTANT!
		{	
			pr->nums[chanceless->cifs[0].val -1].pos = 15;
			pr->nums[chanceless->cifs[0].val -1].try = 15;
			
		}
		if(simplchange == 0)
		{
			for(i=0;i<9;i++)
			{
				if(pr->nums[i].try == 15)
				{
					chanceless->cifs[0].val=pr->nums[i].val;
					i=9;
				}
			}
			
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val=p[toforget].cifs[i].val;

			}
			simplchange=1;
		}
		
		else if(simplchange == 1)
		{
			element=0;
			if(p[cnt].prty == 0.50)
			{
				if(cnt==2)
				{
				  element=notanymore(&p[toplay], &p[cnt]) -1;
				}
				
				else if(cnt > 2)
				{
				  element=notanymore(&p[cnt-1], &p[cnt]) -1;
				}	
				
				pr->nums[element].pos |= 16;
				pr->nums[element].try |= 16;	
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				 	chanceless->cifs[i].val = pr->nums[element].val;
					i=4; 
				  }
				}	
				
				if(chanceless->cifs[3].val > 0)
				{
					element=notanymore(&p[cnt], chanceless) -1;
					pr->nums[element].pos=-1;
					pr->nums[element].try=-1;
					
					pr->nums[chanceless->cifs[0].val -1].pos = -1;	
					pr->nums[chanceless->cifs[0].val -1].try = -1;	

					//Temorally hole
					for(i=0;i<4;i++)
					{
						element=p[toplay].cifs[i].val -1;
						if(((pr->nums[element].pos & 16) == 16) &&
						     pr->nums[element].pos != -1)
						{
							pr->nums[element].pos ^= 16;
							pr->nums[element].try ^= 16;
						}
					}
					h_clear(chanceless);
					h_clear(justout);
					simplchange=2;
				}
				
			}
			else if(p[cnt].prty == 0.75)
			{
				if(cnt==2)	
				  element=notanymore(&p[toplay], &p[cnt]) -1;
				
				else if(cnt > 2)
				  element=notanymore(&p[cnt-1], &p[cnt]) -1;
				
				pr->nums[element].pos = -1;
				pr->nums[element].try = -1;
		
				pr->nums[chanceless->cifs[0].val -1].pos = -1;
				pr->nums[chanceless->cifs[0].val -1].try = -1;

				//Temorally hole
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(((pr->nums[element].pos & 16) == 16) &&
					   pr->nums[element].pos != -1)
					{
						pr->nums[element].pos ^= 16;
						pr->nums[element].try ^= 16;
					}
				}
				
				h_clear(chanceless);
				h_clear(justout);
				simplchange=2;


			}	
			
			
	
		}
		if(simplchange==2)
		{
			y=0;
			if(swich == 0)
			{
			  for(i=0;i<4;i++)
			  {
			  	  element=p[toplay].cifs[i].val -1;
				  if(pr->nums[element].pos >= 1 && y<=1 )
				  {	
					  chanceless->cifs[y].val= pr->nums[element].val;
					  y++;
				  }
				  else if( y > 1)
				  {
					  justout->cifs[y -2].val= pr->nums[element].val;
					  i=4;
				  }
			  }
			swich=1;
			}
			
			else if(swich == 1)
			{
				if(p[cnt].prty == 0.50) //No esta en el par
				{
				  for(i=0;i<4;i++)
				  {
				    element=p[cnt].cifs[i].val -1;
				    if(pr->nums[element].val != chanceless->cifs[0].val &&
				       pr->nums[element].val != chanceless->cifs[1].val &&
				       pr->nums[element].val != chanceless->cifs[2].val &&
				       pr->nums[element].val != chanceless->cifs[3].val )
				    {
					pr->nums[element].pos = -1;
					pr->nums[element].pos = -1;
				    }
				  }
				}
				else if(p[cnt].prty == 0.75) // esta en el par
				{
				  for(i=0;i<4;i++)
				  {		
				    element=p[toforget].cifs[i].val -1;
				    if(pr->nums[element].val != p[cnt].cifs[0].val &&
				       pr->nums[element].val != p[cnt].cifs[1].val &&
				       pr->nums[element].val != p[cnt].cifs[2].val &&
				       pr->nums[element].val != p[cnt].cifs[3].val )
				     {
					pr->nums[element].pos = -1;
					pr->nums[element].try = -1;
				     }
				   }
				}
			


	  
			 	element=justout->cifs[0].val -1;
			 	for(i=0;i<4;i++)
			 	{
					if(chanceless->cifs[i].val == 0)
					{
				 	    chanceless->cifs[i].val = pr->nums[element].val;
					    h_clear(justout);
					    i=4;
					}
			 	}		
				simplchange=3;		
					
			}//swich==1
		}
			
		else if(simplchange == 3)
		{
			if(fibyn == 1)
			{
				for(i=0;i<4;i++)
				{
				    element=p[toforget].cifs[i].val -1;
				    if(pr->nums[element].val == p[cnt].cifs[0].val ||
				       pr->nums[element].val == p[cnt].cifs[1].val ||
				       pr->nums[element].val == p[cnt].cifs[2].val ||
				       pr->nums[element].val == p[cnt].cifs[3].val)
				    {
					pr->nums[element].pos=-1;
					pr->nums[element].try=-1;
				    }
				}
				h_clear(chanceless);
			
				for(i=0;i<9;i++)
				{
					if(pr->nums[i].pos > -1)
					{
						pr->nums[i].pos |= 16;	
						pr->nums[i].try |= 16;	
						for(y=0;y<4;y++)
						{
						   if(chanceless->cifs[y].val == 0)
						   {
							chanceless->cifs[y].val =
							pr->nums[i].val;
							y=4;
						   }
						}
					}
				}
			}//if(fibyn == 1)
		}//if(simplchange==3)
	}//GR4_PRTY75_25	
	
	else if(flag == GR4_PRTY50_50)
	{
		toplay=0;
		toforget=1;
		
		if(simplchange == 0)
		{
			for(i=0;i<4;i++)
			{
				justout->cifs[i].val = p[toforget].cifs[i].val;
				
			}
			for(i=0;i<9;i++)
			{
				if(pr->nums[i].try == 15)
				{
					chanceless->cifs[0].val = pr->nums[i].val;
					i=9;
				}
			}

			simplchange=1;
		}
		
		else if(simplchange == 1)	
		{
			if(p[cnt].prty == 0.5)
			{
				element=notanymore(&p[toplay], &p[cnt]) -1;
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				    chanceless->cifs[i].val = pr->nums[element].val;
				    i=4; 
				  }
				}
				twooutbag++;
			}
			else if(p[cnt].prty == 0.25)
			{
				element=notanymore(&p[toplay], &p[cnt]) -1;
				pr->nums[element].pos |= 16;
				pr->nums[element].try |= 16;
				for(i=0;i<4;i++)
				{
				  if(chanceless->cifs[i].val == 0)
				  {
				    chanceless->cifs[i].val = pr->nums[element].val;
				    i=4;
				  }
				}
				twoinbag++;
			}	
			
			if(twooutbag == 2)
			{
				for(i=0;i<4;i++)
				{
					element=chanceless->cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
						
					}	
				}
				for(i=0;i<4;i++)
				{
					element=p[toplay].cifs[i].val -1;
					if(pr->nums[element].pos != -1 && 
					   pr->nums[element].pos < 16)
					{
						pr->nums[element].pos |= 16;
						pr->nums[element].try |= 16;
					}
				}
			}
			if(twoinbag==2)
			{
				for(i=0;i<4;i++)
				{
					element=p[toplay].cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
					}
				}
			}

			if(twoinbag == 2 || twooutbag == 2)
			{
				twoinbag=0;
				twooutbag=0;
				h_clear(chanceless);
				h_clear(justout);
				simplchange=2;
			}
		}

		else if(simplchange == 2)
		{
			if(p[cnt].prty == 0.5)
			{
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(pr->nums[element].pos < 16)
					{
						pr->nums[element].pos = -1;
						pr->nums[element].try = -1;
					}		

				}
				h_clear(chanceless);
				h_clear(justout);
			}
			else if(p[cnt].prty == 0.75)
			{
				y=0;
				for(i=0;i<4;i++)
				{
					element=p[cnt].cifs[i].val -1;
					if(pr->nums[element].pos < 16 && 
					   pr->nums[element].val != justout->cifs[0].val)
					{
						y++;
					}				

					if(y == 1)
					{
					 justout->cifs[0].val = pr->nums[element].val;
					 if(chanceless->cifs[0].val == 0)	
						 y=10;
					}
				
					else if(y == 11)
					{
					 chanceless->cifs[0].val = pr->nums[element].val;
					 i=4;
					}
				}
			}		
		}
	}	


	for(i=0;i<9;i++)
	{	
		if(pr->nums[i].pos >= 16)
			nervo_addint(pr->nums[i].val, temp);
	}
	return 0;
}		


int justgoods(struct prob *pr, struct posib p[])
{
	int i, y;
	for(i=cnt; i>-1; i--)
	{
		if(p[i].jgoods==1)
		{
			for(y=0; y<4; y++)
			{
			   if(p[cnt].cifs[0].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[0].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[0].val -1].try = (p[i].cifs[y].pos | 16);
			   }
		
			   if(p[cnt].cifs[1].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[1].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[1].val -1].try = (p[i].cifs[y].pos | 16);
			   }
				
			   if(p[cnt].cifs[2].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[2].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[2].val -1].try = (p[i].cifs[y].pos | 16);
			   }

		  	   if(p[cnt].cifs[3].val == p[i].cifs[y].val)
			   {
			    pr->nums[p[cnt].cifs[3].val -1].pos = (p[i].cifs[y].pos | 16);
			    pr->nums[p[cnt].cifs[3].val -1].try = (p[i].cifs[y].pos | 16);
			   }
			}
		}
	}
	return 0;
}



	


int fourinbag(struct prob *pr, struct posib *p)
{
	int i;
	
	if(fibyn == 1)
	{
	pr->val=0; //Vaciado temporal
	
	for(i=0; i<9; i++)
	{
		if(i < 4)
		{
		pr->val= pr->val | pos(p->cifs[i].val);
		pr->nums[p->cifs[i].val -1].pos = (pr->nums[p->cifs[i].val -1].pos | 16);
		pr->nums[p->cifs[i].val -1].try = (pr->nums[p->cifs[i].val -1].try | 16);
		}
	

		if(pr->nums[i].val != p->cifs[0].val)
			if(pr->nums[i].val != p->cifs[1].val)
				if(pr->nums[i].val != p->cifs[2].val)
					if(pr->nums[i].val != p->cifs[3].val)
					{
						pr->nums[i].try=-1;
						pr->nums[i].pos=-1;
					}
	}
	}
	

	fibyn=0;
	return 0;
}	



int vkp_debug(struct posib *p, struct prob *pr, struct hidden *secret, struct hidden *temp,
		struct hidden *chanceless, struct hidden *justout)
{
	int i, y, element, ming=0, minr=0;

///////////////////////// No body is gonna safe /////////////////////	
	for(i=0; i<9; i++)
	{
		if(pr->nums[i].pos==0)
		{	
			pr->nums[i].pos=-1;
			pr->nums[i].try=-1;	
			pr->val= (pr->val ^ pos(pr->nums[i].val));
		}
		else if(pr->nums[i].pos == -1)
		{
			pr->val= (pr->val ^ pos(pr->nums[i].val));
		}	
	}
	
	for(i=0; i<4; i++)
	{
		element=(p->cifs[i].val -1);
		if(pr->nums[element].try != 0)
		{
			switch(i)
			{
				case 0:
					pr->nums[element].try= (pr->nums[element].try ^ 8);
					break;
				case 1:
					pr->nums[element].try= (pr->nums[element].try ^ 4);
					break;
				case 2:
					pr->nums[element].try= (pr->nums[element].try ^ 2);
					break;
				case 3:
					pr->nums[element].try= (pr->nums[element].try ^ 1);
					break;
			}
		}
		if(pr->nums[element].try == 0 || pr->nums[element].try == 16) 
			pr->nums[element].try = pr->nums[element].pos;

	}	
				
	if(cnt == 1)
	{
		if(gr == 3)
		{
			for(i==0; i<9; i++)
			{	
				if(pr->nums[i].try == 15)
				{
					nervo_addint(pr->nums[i].val, temp);
					pr->nums[i].try |= 16;
					pr->nums[i].pos |= 16;
					i=10;
				}
			}		
		}	
	}	

////////////////////////// Just for some stupids /////////////////////

	if(p->goods == 4)
	{	
		printf("I WIN!\n");
		exit(1);
	}
	else if( (p->goods + p->regs) == 4)
	{
		fourinbag(pr, p);
		h_clear(chanceless);
		h_clear(justout);
	}
	if(p->goods>0 && p->goods<4 && p->regs==0 && autodebug==0)
	{	
		p->jgoods=1;
		jgds++;
	}
	if( p->goods == 0)
	{
		if(p->regs == 0)
		{
			for(i=0; i<4; i++)
			{
				element=(p->cifs[i].val) -1;
				for(y=0; y< 4; y++)
				{
					if(pr->nums[element].val == secret->cifs[y].val)
						y=11;
				}
				if(y<5)
				{
					pr->nums[element].pos=0;
					pr->nums[element].try=-1;
					pr->val=(pr->val) ^ pos(element+1);
				}
			}
		}

		else
		{
		
			for(i=0; i<4; i++)
			{	
				element=(p->cifs[i].val) -1;
				pr->nums[element].pos= p->cifs[i].pos ^ pr->nums[element].pos;	
				pr->nums[element].try &= pr->nums[element].pos;
				switch(pr->nums[element].pos)
				{
				case 17:
					pr->nums[element].try = pr->nums[element].pos;
					secret->cifs[3].val=pr->nums[element].val;
					secret->val= secret->val | 1;
					ming++;
					minr--;
					break;
				case 18:
					pr->nums[element].try = pr->nums[element].pos;
					secret->cifs[2].val=pr->nums[element].val;
					secret->val= secret->val | 2;
					ming++;
					minr--;
					break;
				case 20:
					pr->nums[element].try = pr->nums[element].pos;
					secret->cifs[1].val=pr->nums[element].val;
					secret->val= secret->val | 4;
					ming++;
					minr--;
					break;
				case 24:
					pr->nums[element].try = pr->nums[element].pos;
					secret->cifs[0].val=pr->nums[element].val;
					secret->val= secret->val | 8;
					ming++;
					minr--;
					break;
				}
			}
		}
	}
	return 0;
}

int knowns_fill(struct prob *pr)
{
	char i, ret=0;

	for(i=0;i<9;i++)
	{
		if(pr->nums[i].try >= 16 && pr->nums[i].try <=31)
			ret++;
	}
	knowns =ret;
	return 0;
}

int nervo_addint(int val, struct hidden *temp)
{
	int i;
	char turn=0;

	for(i=0;i<4;i++)
	{
		if(temp->cifs[i].val == val)
			turn=1;
	}
	if(turn ==0)
	{
		for(i=0;i<4;i++)
		{
			if(temp->cifs[i].val == 0)
			{
				temp->cifs[i].val=val;
				i=5;
			}
		}
	}
	return 0;
}

		




int vkp_filtrator(struct hidden *secret, struct prob *pr, struct hidden *justout)
{
	
	int i, y; 
	char a, b ,c ,d, v8, v4, v2, v1;
	char knowns=0;
	a=b=c=d=v8=v4=v2=v1=0;
	
	for(i=0; i<9; i++)
	{
		for(y=0; y < 4; y++)
		{
			if(pr->nums[i].val == secret->cifs[y].val)
				y=5;
		}
		if(y < 5 )
		{
		
			if(((pr->nums[i].pos & secret->val) == secret->val) &&
			    (pr->nums[i].pos != -1))
			{
				pr->nums[i].pos= pr->nums[i].pos ^ secret->val;
				pr->nums[i].try= pr->nums[i].try & pr->nums[i].pos;
			
				if(pr->nums[i].try == 0)
					pr->nums[i].try= pr->nums[i].pos;
			}
		}
	
	//leer vkp_filtrator.txt
	if(pr->nums[i].try == 17 || pr->nums[i].try == 18 || pr->nums[i].try == 20 || 
	   pr->nums[i].try == 24) //Evitamos que se repita una cifra con valor try minimo
	{
		switch(pr->nums[i].try)
		{
			case 17:
				if(a != 0)
				{
					if(a>0)
						pr->nums[a-1].try = pr->nums[a-1].pos;
					else
						pr->nums[i].try = pr->nums[i].pos;
				
				}
				
				else if(pr->nums[i].pos != 17 )
					a=(pr->nums[i].val);
				else
					a=-1;
				break;
			case 18:
				if(b != 0)
				{
					if(b>0)
						pr->nums[b-1].try = pr->nums[b-1].pos;
					else
						pr->nums[i].try=pr->nums[i].pos;
				}
				
				else if(pr->nums[i].pos != 18)
					b=(pr->nums[i].val);
				else;
					b=-1;
				break;
			case 20:
				if(c != 0)
				{
					if(c>0)
						pr->nums[c-1].try = pr->nums[c-1].pos;
					else
						pr->nums[i].try = pr->nums[i].pos;
				}
				else if(pr->nums[i].pos != 20)
					c=(pr->nums[i].val);
				else
					c=-1;
				break;
			case 24:
				if(d != 0)
				{
					if(d>0)
						pr->nums[d-1].try = pr->nums[d-1].pos;
					else
						pr->nums[i].try=pr->nums[i].pos;
				}
				else if(pr->nums[i].pos != 24)
					d=(pr->nums[i].val);
				else
					d=-1;
				break;
		}

	}
	//ver vkp_filtrator.txt ->apendice 2
	
	if(((pr->nums[i].try & 8) == 8) && (pr->nums[i].try != -1) && 
	     deadline(pr->nums[i].val, justout) == 0)
		v8++;
	if(((pr->nums[i].try & 4) == 4) && (pr->nums[i].try != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v4++;
	if(((pr->nums[i].try & 2) == 2) && (pr->nums[i].try != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v2++;
	if(((pr->nums[i].try & 1) == 1) && (pr->nums[i].try != -1) &&
	     deadline(pr->nums[i].val, justout) == 0)
		v1++;


	/////////////////Another thing/////////////
	if(pr->nums[i].try >= 16 || pr->nums[i].try <=31)
		knowns++;

	///////////////////////////////////////////
	
	} //for


	if(v8==0 || v4==0 || v2==0 || v1==0)
	{
	
		if(v8==0)
		{
			for(y=0;y<9;y++)
			{
				if(((pr->nums[y].pos & 8) == 8) && (pr->nums[y].pos != -1))
					pr->nums[y].try = (pr->nums[y].try | 8);
			}
		}		
		if(v4==0)
		{
			for(y=0; y<9; y++)
			{
				if(((pr->nums[y].pos & 4) == 4) && (pr->nums[y].pos != -1))
					pr->nums[y].try = (pr->nums[y].try | 4);
			}
		}
		if(v2==0)
		{
			for(y=0; i<9; y++)
			{
				if(((pr->nums[y].pos & 2) == 2) && (pr->nums[y].pos != -1))
					pr->nums[y].try = (pr->nums[y].try | 2);
			}
		}
		if(v1==0)
		{
			for(y=0; y<9; y++)
			{
				if(((pr->nums[y].pos & 1) == 1) && (pr->nums[y].pos != -1))
					pr->nums[y].try = (pr->nums[y].try | 1);
			}
		} 
		
	}	
		
	
	a=b=c=d=v8=v4=v2=v1=0;

	
	return 0;
	
}
		


int main(int count, char *args[])
{
	struct posib p[10];
	struct prob pr;
	struct hidden secret;
	struct hidden temp;
	struct hidden chanceless;
	struct hidden justout;
	int i, retbc=-1, build_flag=GOAHEAD;
	char miss=0;
	
	h_clear(&justout);
	h_clear(&chanceless);
	h_clear(&temp);
	h_clear(&secret);
	pr_clear(&pr);
	start(&pr);
	autodebug = 0; //Para limitar operaciones interas de vkp_debug(), ej. jgoods=1

	for(i=0; i<9; i++)
		p_clear(&p[i]);

	for(i=0;i>-1 ;i++ )
	{
		knowns_fill(&pr);
		
	
		if(buildyn == 1)
		{
			
			build(&pr, &p[i], GOAHEAD, &justout, cnt);
			if(build_check(&pr, p, &chanceless, &justout) == -1)
			{	
				retbc=-1;
				autodebug=1;
				while(retbc == -1)
				{	
					knowns_fill(&pr);
					p_clear(&p[cnt]);
					p[cnt].goods=3;
					build(&pr, &p[i], build_flag, &justout, cnt);
					vkp_debug(&p[i], &pr, &secret, &temp, &chanceless,
						  &justout);
					vkp_filtrator(&secret, &pr, &justout);
					retbc=build_check(&pr, p, &chanceless, &justout);
				
				 miss++;
				 if(miss > 16) //WARNING
				 	build_flag=GOBACK;
				 }
				autodebug=0;
			} 
		}
		build_flag=GOAHEAD; //Calming down again
		miss=0;
		show(&p[i]);	
		ask(&p[i]);
		
		gr= p[0].goods + p[0].regs + p[1].goods + p[1].regs;
	
		vkp_debug(&p[i], &pr, &secret, &temp, &chanceless, &justout);
		vkp_filtrator(&secret, &pr, &justout);
		
		if(p[cnt].goods + p[cnt].regs == 4)
			justgoods(&pr, p);
		
		if(cnt >= 1 && fibyn==1)
		{
		  vkp_simplificator(&pr, p, situation(&p[0]), &temp, &chanceless, &justout);
		}



		
		cnt++;
		knowns=0;
	}
	return 0;
}

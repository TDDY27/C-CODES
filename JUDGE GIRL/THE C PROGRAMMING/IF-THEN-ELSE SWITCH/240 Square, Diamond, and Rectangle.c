#include <stdio.h>

struct pnt{
    int x;
    int y;
};

int n;
struct pnt p,q,r,s;

int dot(struct pnt a,struct pnt b,struct pnt c){
    return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

int crs(struct pnt a,struct pnt b,struct pnt c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int dis(struct pnt a,struct pnt b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void swi(struct pnt *a,struct pnt *b){
    struct pnt tmp=*a;
    *a=*b, *b=tmp;
}

signed main(){
    scanf("%d", &n);
    while(n>0){
        scanf("%d%d%d%d%d%d%d%d", &p.x,&p.y,&q.x,&q.y,&r.x,&r.y,&s.x,&s.y);

        if(crs(p,q,r)<0) swi(&q,&r);
        if(crs(p,q,s)<0) swi(&q,&s);
        if(crs(p,r,s)<0) swi(&r,&s);
        //sort the point by anti-clockwise

        if(dot(p,q,s)==0 && dot(q,r,p)==0 && dot(r,s,q)==0 && dot(s,p,r)==0){
            if(dis(p,q)==dis(q,r)) printf("square\n");
            else printf("rectangle\n");
        }else if(dis(p,q)==dis(q,r) && dis(q,r)==dis(r,s) && dis(r,s)==dis(s,p) && dis(s,p)==dis(p,q)){
            printf("diamond\n");
        }else printf("other\n");

        n--;
    }

}

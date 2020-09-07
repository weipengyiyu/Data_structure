#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "array.h"
#include "list.h"

#define MSG_SUB_NET "192.168.127"
void msg_id2ip(int id, char * ipstr)
{
	sprintf(ipstr,MSG_SUB_NET".%d", *(char*) &id);
}

static char _ipstr[16];
int msg_ip2id(const char* ip)
{
	memcpy(_ipstr, ip, sizeof(_ipstr));
	char *token = strtok(_ipstr,".");
	char *last;
	int id;
	int iptail;

	id = 0x6000;
	while (token != NULL)
	{
		last = token;
		token = strtok(NULL, ".");
	}
	iptail = atoi(last);
	return id|iptail;
}

void test_ip_id(void)
{
    int id = 6000;
    char ipstr[16];
    //msg_id2ip(id, ipstr);
    sprintf(ipstr,MSG_SUB_NET".%d", *(char*) &id);
    printf("%d!\n", *(char*) &id);
    printf("%s!\n", ipstr);

    id = msg_ip2id("192.168.127.116");
    printf("%d!\n", *(char*) &id | 6000);
}

typedef struct node
{
    int a;
    int b;
    int c;
}NODE;

void test_hash_table(void)
{
    HashTableConf conf;
    HashTable *table;
    int stat = CC_OK;
    int id = 6000;
    NODE *n = (NODE*)malloc(sizeof(NODE));
    NODE *out = (NODE*)malloc(sizeof(NODE));
    NODE *out1 = (NODE*)malloc(sizeof(NODE));

    memset(out, 0, sizeof(NODE));
    memset(out1, 0, sizeof(NODE));
    //hashtable_conf_init(&conf);

    hashtable_new(&table);
    //stat = hashtable_new_conf(&conf, &table);
    if(stat != CC_OK)
    {
        printf("err!\n");
    }
    else
    {
        printf("succeeful!\n");
    }

    n->a = 1;
    n->b = 2;
    n->c = 3;
    if(hashtable_add(table, "key", n) != CC_OK)
    {
        printf("err1!\n");
    }
    else
    {
        printf("succeeful1!\n");
    }
    n->a = 4;
    n->b = 5;
    n->c = 6;
        if(hashtable_add(table, &id, n) != CC_OK)
    {
        printf("err1!\n");
    }
    else
    {
        printf("succeeful2!\n");
    }
    n->a = 7;
    n->b = 8;
    n->c = 9;
        if(hashtable_add(table, "wei", n) != CC_OK)
    {
        printf("err3!\n");
    }
    else
    {
        printf("succeeful3!\n");
    }
    n->a = 11;
    n->b = 12;
    n->c = 13;
        if(hashtable_add(table, "peng", n) != CC_OK)
    {
        printf("err4!\n");
    }
    else
    {
        printf("succeeful4!\n");
    }
    n->a = 14;
    n->b = 15;
    n->c = 16;
        if(hashtable_add(table, "weipeng", n) != CC_OK)
    {
        printf("err5!\n");
    }
    else
    {
        printf("succeeful5!\n");
    }
    n->a = 17;
    n->b = 18;
    n->c = 19;
        if(hashtable_add(table, "yi", n) != CC_OK)
    {
        printf("err!6\n");
    }
    else
    {
        printf("succeeful6!\n");
    }
    n->a = 21;
    n->b = 22;
    n->c = 23;
        if(hashtable_add(table, "yu", n) != CC_OK)
    {
        printf("err7!\n");
    }
    else
    {
        printf("succeeful7!\n");
    }


    memset(out1, 0, sizeof(NODE));

    if(hashtable_contains_key(table, &id))
    {
        printf("yes!\n");
    }
    else
    {
        printf("no!\n");
    }

    if(hashtable_get(table, "wei", (void*)&out1) != CC_OK)//
    {
        printf("err13!\n");
    }
    else
    {
        printf("succeeful13!\n");
    }
    printf("wei %d %d %d !\n", out1->a, out1->b, out1->c);
    printf("hashtable_size %d hashtable_capacity %d !\n", hashtable_size(table), hashtable_capacity(table) );
    hashtable_remove(table, "wei", &out);
    if(hashtable_contains_key(table, "wei"))
    {
        printf("yes!\n");
    }
    else
    {
        printf("no!\n");
    }
    //rintf("weipeng %d %d %d !\n", out1->a, out1->b, out1->c);
    if(hashtable_get(table, &id, (void*) &out) != CC_OK)
    {
        printf("err13!\n");
    }
    else
    {
        printf("succeeful13!\n");
    }
    printf("wei %d %d %d !\n", out->a, out->b, out->c);

    printf("hashtable_size %d hashtable_capacity %d !\n", hashtable_size(table), hashtable_capacity(table) );

    hashtable_remove_all(table);

        if(hashtable_contains_key(table, &id))
    {
        printf("yes!\n");
    }
    else
    {
        printf("no!\n");
    }

        if(hashtable_get(table, &id, (void*) &out) != CC_OK)
    {
        printf("err13!\n");
    }
    else
    {
        printf("succeeful13!\n");
    }
    printf("wei %d %d %d !\n", out->a, out->b, out->c);


    printf("hashtable_size %d hashtable_capacity %d !\n", hashtable_size(table), hashtable_capacity(table) );
}


static Array *v1;
static Array *v2;
static int stat;
static ArrayConf vc;

void test_array(void)
{
    NODE *n = (NODE*)malloc(sizeof(NODE));
    array_new(&v1);

    n->a = 1;
    array_add(v1, n);
        n->a = 2;
    array_add(v1, n);
        n->a = 3;
    array_add(v1, n);
        n->a = 4;
    array_add(v1, n);
        n->a = 5;
    array_add(v1, n);
    printf("size %d capacity %d !\n", array_size(v1), array_capacity(v1) );
        n->a = 45;
    array_add_at(v1, n, 5);
            n->a = 35;
    array_add(v1, n);
            n->a = 65;
    array_add(v1, n);
            n->a = 75;
    array_add(v1, n);
    array_add_at(v1, n, 9);
            n->a = 15;


    NODE *out = (NODE*)malloc(sizeof(NODE));
    memset(out, 0, sizeof(NODE));
    array_get_last(v1, &out);
    printf("size %d capacity %d out %d!\n", array_size(v1), array_capacity(v1), out->a);

    array_reverse(v1);
    memset(out, 0, sizeof(NODE));
    array_get_last(v1, &out);
    printf("size %d capacity %d out %d!\n", array_size(v1), array_capacity(v1), out->a);

}

static void op(void *value)
{
    printf(" %d \n", *((int*)value));
}
static List *l;
static List *l2;
/*只能依次存入*/
void test_list(void)
{
#if 0
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 6;
    int f = 7;

    list_new(&l);
    list_new(&l2);

    list_add_(l, &a);
    list_add_(l, &b);
    list_add_(l, &c);
    printf("size %d \n", list_size(l));
    list_add_(l, &d);
    list_add_(l, &e);
    printf("size %d \n", list_size(l));

    int *out = NULL;
    list_get_at(l, 3, &out);
    printf("size %d out %d!\n", list_size(l), *out);

    int *out1 = NULL;
    list_add_at(l, &f, 0);          //在原有的基础上添加元素
    list_get_first(l, &out1);
    printf("size %d out %d!\n", list_size(l), *out1);

    ListIter iter;
    list_iter_init(&iter, l);

    int *ee;
   // list_iter_next(&iter, &prev);
    //printf("1prev %d \n", *prev);
    while (list_iter_next(&iter, &ee) != CC_ITER_END) {
       //CHECK_C(*((int*)prev) <= *((int*)ee));
        //prev = ee;
        printf("2prev %d \n", *ee);
    }


    list_add_(l2, &c);
    list_add_(l2, &a);
    list_add_(l2, &b);
    list_add_(l2, &e);
    list_add_(l2, &d);

    ListZipIter zip;
    list_zip_iter_init(&zip, l, l2);

    int *e1;
    int *e2;

    while (list_zip_iter_next(&zip, &e1, &e2) != CC_ITER_END) {
       //CHECK_C(*((int*)prev) <= *((int*)ee));
        //prev = ee;
        printf("e1 %d e2 %d\n", *e1, *e2);
    }
#else
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 6;
    int f = 7;

    list_new(&l);

    list_add_(l, &a);
    list_add_(l, &b);
    list_add_(l, &c);
    list_add_(l, &d);
    list_add_(l, &e);
    list_add_(l, &f);

    list_foreach(l, op);

#endif
}


void test1(int n)
{
    int a = 0;
    int b = 1;
    int counter = 0;
    int temp1 = 0;

    if(counter > n)
        return;

    while(n--)
    {
        counter++;
        temp1 = a;
        a = b;
        b = temp1 + b;
        printf("%d\n", temp1);
    }

    return b;
}

/*用函数迭代行驶完成test1的计算*/
void test2(int n)
{
    static int cnt = 0;
    if(cnt > n)
        return;
    else
    {
        cnt++;
        return test2(cnt);
    }
}

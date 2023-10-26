 #include <stdio.h>
 #include "store.h"
 int main(int argc, char* argv[])
 {
  struct store rec;
 FILE *fp;
 if (argc != 2) {
        fprintf(stderr, "How to use: %s FileName\n", argv[0]);
        return 1;
     }
     fp = fopen(argv[1], "w");
     printf("%-6s %-6s %-6s %-6s %-3s\n", "id", "name", "category", "expired date", "stock");
     while (scanf("%d %s %s  %d %d", &rec.id, rec.name, rec.category, &rec.expireddata  &rec.stock)==5)
        fprintf(fp, "%d %s %s %d  %d ", rec.id, rec.name, rec.category, rec.expireddata,  rec.stock);
     fclose(fp);
 return 0;
     }


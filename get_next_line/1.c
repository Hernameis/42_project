static int   ft_countblock(const char *str, char c)
{
   int block;
   block = 0;
   if (*str && *str != c)
   {
      str++;
      block++;
   }
   while (*str)
   {
      while (*str == c)
      {
         str++;
         if (*str && *str != c)
            block++;
      }
      str++;
   }
   return (block);
}
static int   ft_blocklen(const char *str, char c)
{
   int i;
   i = 0;
   while (str[i] && str[i] != c)
   {
      i++;
   }
   return (i);
}
static void   free_all(char **result)
{
   int i;
   i = 0;
   while (result[i])
   {
      free(result[i]);
      i++;
   }
}            //return (NULL) if *free_all
char   **ft_split(char const *s, char c)
{
   int i;    
   int j;
   char **result;  //result[i][j]
   i = 0;
   if (!s)
      return (0);
   if (!(result = (char **)malloc(sizeof(char *) * (ft_countblock(s, c) + 1))))
      return (0);
   while (*s)
   {
      while (*s && *s ==c)
         s++;
      j = 0;
      if (*s && *s != c)
      {
         if (!(result[i] = (char *)malloc(sizeof(char) * (ft_blocklen(s, c) + 1))))
         {
            free_all(result);
            return (0);
         }
         while (*s && *s != c)
         {
            result[i][j] = (char)*s;
            j++;
            s++;
         }
         result[i][j] = '\0';
         i++;
      }
   }
   result[i] = 0;
   return (result);
}

int   main(void)
{
   int i;
   char *str;
   char **result;
   i = 0;
   str = "hello world";
   result = ft_split(str, 'l');
   while (result[i])
   {
      printf("%s\n", result[i]);
      i++;
   }
   return (0);
}

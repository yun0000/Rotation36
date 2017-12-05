int gendata() {
	if (scanf("%d", &n) == EOF) {
		return 0;
	}
	else {
		scanf("%d", &d);
		str = (char*)malloc(sizeof(char)*(n + 1));
		for (int i = 0; i < n; i++) {
			str[i] = i % 26 + 65;
		}
		str[n] = '\0';
		return 1;
	}
}

void trivial(char*tri) {
	char c;
	for (int count = 0; count<d; count++) {
		for (int i = 0; i < n - 1; i++) {
			c = tri[i];
			tri[i] = tri[i + 1];
			tri[i + 1] = c;
		}
	}
}

void juggle(char *jug) {
	char *temp = (char*)malloc(sizeof(char)*(d + 1));
	int count = 0;
	strncpy(temp, jug, d);
	for (count = 0; count < (n / d) - 1; count++) {
		strncpy(jug + d*count, jug + d*(count + 1), d);
	}
	strncpy(jug + d*count, jug + d*(count + 1), n - d*(count + 1));
	strncpy(jug + (n - d), temp, d);
	jug[n] = '\0';
	free(temp);
}

void blockswap(char *str, int d, int n) 
{	
	if (d == 0 || d == n)
	{
		return;
	}
	
	if (n - d == d)
	{
		swap(str, 0, n-d, d);
		return;
	}
	else 
	{
		swap(str, 0, d, n-d);
		blockswap(str + n - d, (2*d)-n, d);
	}
}


void printhead() 
{		
	printf("StrLength\tRotateDistance\tT.trivial\tT.juggle\tT.bw\t\tT.reverse\t\n");
}

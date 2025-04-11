// hàm tính lũy thừa
int luy_thua(int x, int n)
{
	if (n == 0)	return 1; // điều kiện dừng
	return x * luy_thua(x, n - 1); // đệ quy với n * lũy thừa của x với n - 1

}

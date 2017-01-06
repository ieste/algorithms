#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
	private:
	vi D;
	vi A;
	void build(int index, int i, int j);
	int rmq(int index, int i, int j, int a, int b);

public:
	SegmentTree(const vi &);
	int RMQ(int i, int j);
	void update(int i, int val);
};


SegmentTree::SegmentTree(const vi &_A) {
	
	A = _A;
	D = vi(2*A.size());

	build(1, 0, A.size()-1);


}

void SegmentTree::build(int index, int i, int j) {

	if (i == j) {
		D[index] = i;
		return;
	}

	build(2*index, i, (i+j)/2);
	build(2*index+1, (i+j)/2+1, j);

	D[index] = A[D[2*index]] <= A[D[2*index+1]] ? D[2*index] : D[2*index+1];
}

int SegmentTree::RMQ(int i, int j) {

	return rmq(1, i, j, 0, A.size()-1);	
}

int SegmentTree::rmq(int index, int i, int j, int a, int b) {
	
	int k, l;

	if (i > b || j < a) return -1;
	if (i <=a && j >= b) return D[index];

	k = rmq(index*2, i, j, a, (a+b)/2);
	l = rmq(index*2+1, i, j, (a+b)/2+1, b);

	if (k == -1) return l;
	if (l == -1) return k;
	return A[k] <= A[l] ? k : l;

	
}


int main() {
	int A[] = {18, 17, 13, 19, 15, 11, 20};
	vi arr(A, A+7);

	SegmentTree st(arr);
	
	printf("%d\n%d\n", st.RMQ(1, 3), st.RMQ(4, 6));
	printf("%d\n%d\n", st.RMQ(0, 0), st.RMQ(0, 1));
	printf("%d\n%d\n", st.RMQ(0, 6), st.RMQ(4, 6));

}

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
		int n = A.size();
		for (int i = 0; i < n; i++) {
        	    if (abs(A[i] - i) > 1) return false;
		}
		return true;
    }
};
 // 왜이렇게 어려운걸까룡!!!!!!!!!!!! 잘모르겟음



/*class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int global = 0, local = 0;
        int len = A.size();
        for (int i = 0; i < len-1; i++) {
            for (int j = i; j < len; j++) {
                if (A[i] > A[j]) global++;
            }
            if (A[i] > A[i + 1]) local++;
        }
        return (local==global);
    }
};

// 시간 초과
// fail
*/

/*class Solution {
public:
bool isIdealPermutation(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j++) {
			if (A[i] > A[j]) return false;
		}
	}
	return true;
}

*/ 
// 이것도 시간초과야 ㅠ

#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq)
	{
		left = right = nullptr;
		this->data = data;
		this->freq = freq;
	}
};

void printCodes(struct MinHeapNode *root, string str)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->data != '$')
	{
		cout << setw(10) << left << root->data << " | " << setw(12) << root->freq << " | " << str << endl;
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

struct compare
{
	bool operator()(MinHeapNode *a, MinHeapNode *b)
	{
		return (a->freq > b->freq);
	}
};

int calculateBitsWithoutHuffman(int freq[], int size)
{
	int totalBits = 0;
	for (int i = 0; i < size; i++)
	{
		totalBits += freq[i];
	}
	return totalBits * 8; 
}

int calculateBitsAfterHuffman(struct MinHeapNode *root, int depth)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root->data != '$')
	{
		return root->freq * depth;
	}
	return calculateBitsAfterHuffman(root->left, depth + 1) + calculateBitsAfterHuffman(root->right, depth + 1);
}

void HuffmanCode(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *temp;

	priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

	cout << "----------------------------------------" << endl;
	cout << setw(10) << "Symbol"
		 << " | " << setw(12) << "Frequency"
		 << " | "
		 << "Huffman Code" << endl;
	cout << "-----------|--------------|-------------" << endl;

	for (int i = 0; i < size; i++)
	{
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}

	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		temp = new MinHeapNode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}

	printCodes(minHeap.top(), "");

	int bitsWithoutHuffman = calculateBitsWithoutHuffman(freq, size);
	int bitsAfterHuffman = calculateBitsAfterHuffman(minHeap.top(), 0);

	cout << "Total bits without Huffman: " << bitsWithoutHuffman << " bits" << endl;
	cout << "Total bits after Huffman: " << bitsAfterHuffman << " bits" << endl;
}

int main()
{
	int n = 0;
	cout << "Enter no. of characters: ";
	cin >> n;
	char data[n];
	int freq[n];
	cout << "Enter " << n << " characters and their frequencies:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		cin >> freq[i];
	}

	HuffmanCode(data, freq, n);

	return 0;
}

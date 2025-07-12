11.4:
Change the permutations function of Section 11.6 (which computed all permutations at once) to a PermutationIterator (which computes them one at a time).

class PermutationIterator
{
public:
   PermutationIterator(string s) { . . . }
   string next_permutation() { . . . }
   bool has_more_permutations() { . . . }
};
Here is how you would print out all permutations of the string "eat":

PermutationIterator iter("eat");
while (iter.has_more_permutations())
{
   cout << iter.next_permutation() << endl;
}
Now we need a way to iterate through the permutations recursively. Consider the string "eat". As before, we’ll generate all permutations that start with the letter 'e', then those that start with 'a', and finally those that start with 't'. How do we generate the permutations that start with 'e'? Make another PermutationIterator object (called tail_iterator) that iterates through the permutations of the substring "at". In the next_permutation function, simply ask tail_iterator what its next permutation is, and then add the 'e' at the front. However, there is one special case. When the tail iterator runs out of permutations, all permutations that start with the current letter have been enumerated. Then

Increment the current position.
Compute the tail string that contains all letters except for the current one.
Make a new permutation iterator for the tail string.
You are done when the current position has reached the end of the string.



12.7:
Implement the merge_sort function without recursion, where the size of the array is an arbitrary number. Hint: Keep merging adjacent areas whose size is a power of 2, and pay special attention to the last area whose size is less.

bool isPossible(vector<int> &boards, int n, int k, int mid)
{
    int painterSum = 1;
    int areaSum = 0;

    for(int i=0; i<n; i++)
    {
        if(areaSum + boards[i] <= mid)
        {
            areaSum += boards[i];
        }
        else
        {
            painterSum++;
            if(painterSum > k || boards[i] > mid)
            {
                return false;
            }
            areaSum = boards[i];
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int s = 0;

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += boards[i];
    }
    int e = sum;

    int ans = -1;

    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(isPossible(boards, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;
}

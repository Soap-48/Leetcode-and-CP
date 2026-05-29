class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        # l,r=0,len(cardPoints)-1
        # c=k-1
        # ans=0
        # while l<=r and c<k:
        #     c+=1
        #     if cardPoints[l]>cardPoints[r]:
        #         ans+=cardPoints[l]
        #         l+=1
        #     elif cardPoints[l]<cardPoints[r]:
        #         ans+=cardPoints[r]
        #         r-=1
        #     else:
        #         def func(a,b):
        #             if a>=b:
        #                 return 0
        #             if cardPoints[a]>cardPoints[b]:
        #                 return 0
        #             elif cardPoints[a]<cardPoints[b]:
        #                 return 1
        #             else:
        #                 return func(a+1,b-1)
        #         if func(l,r):
        #             ans+=cardPoints[r]
        #             r-=1
        #         else:
        #             ans+=cardPoints[l]
        #             l+=1
        # return ans
        l,r,ans,sum1,sum2=k,len(cardPoints),0,0,0
        for i in range(k):
            sum1+=cardPoints[i]
        ans=sum1
        for i in range(k):
            l-=1
            r-=1
            sum1-=cardPoints[l]
            sum2+=cardPoints[r]
            ans=max(ans,sum1+sum2)
        return ans
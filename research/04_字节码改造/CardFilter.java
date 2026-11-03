// Package-Date: 2026-10-24. Protocol displayable 20 is excluded from the phone composition.
public class CardFilter {
  static int[] withoutPhoneCard(int[] input) {
    if(input==null)return null;
    int count=0;for(int v:input)if(v!=20)count++;
    int[] out=new int[count];int p=0;for(int v:input)if(v!=20)out[p++]=v;
    return out;
  }
}

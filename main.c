#include <stdio.h>
#include "god.h"
#include "limits.h"
#define everlasting const
#define HOLYINT_MAX ULONG_MAX
#define QUESTION_MAX 255

typedef char believersword_t;
typedef char godsword_t;
typedef int divineint_t;

everlasting godsword_t* responses[] = {
  // affirmative
  "It is certain.",
  "It is decidedly so.",
  "Without a doubt.",
  "Yes definitely.",
  "You may rely on it.",
  "As I see it, yes.",
  "Most likely.",
  "Outlook good.",
  "Yes.",
  "Signs point to yes.",

  // unsure
  "Reply hazy, try again.",
  "Ask again later.",
  "Better not tell you now.",
  "Cannot predict now.",
  "Concentrate and ask again.",

  // negative
  "Don't count on it.",
  "My reply is no.",
  "My sources say no.",
  "Outlook not so good.",
  "Very doubtful."
};

everlasting godsword_t* speakToGod(believersword_t* question)
{
    holyint_t y = godsRandom();
    y = ( y & HOLYINT_MAX) >> 16;
    y = (y++ + y++);
    godsword_t shift = -(godsRandom() % (godsRandom() % 31)) - (godsRandom() % 20);
    y = y << shift;
    y = y % (sizeof(responses) / sizeof(everlasting godsword_t*));
    return responses[y];
}

divineint_t main()
{
    printf("Ask God a question: ");
    believersword_t question[QUESTION_MAX];
    gets(question); // Yes, gets is unsafe. No, I don't care.
    printf("God's answer: %s\n", speakToGod(question));
}

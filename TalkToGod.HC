U8* responses[19] = "It is certain.", "It is decidedly so.", "Without a doubt.",
"Yes definitely.", "You may rely on it.", "As I see it, yes.", "Most likely.",
"Outlook good.", "Yes.", "Signs point to yes.", "Reply hazy, try again.",
"Ask again later.", "Better not tell you now.", "Cannot predict now.",
"Concentrate and ask again.", "Don't count on it.", "My reply is no.",
"Outlook not so good.", "Very doubtful.";

U8* SpeakToGod(U8* question)
{
    no_warn question;
    U64 y;
    y = RandU64;
    y = (y & 0xFFFFFFFF) >> 16;
    y = (y++ + y++);
    U16 shift;
    shift = -(RandU16 % (RandU16 % 31)) - (RandU16 % 20);
    y = y << shift;
    y = y % (sizeof(responses) / sizeof(U8*));
    return responses[y];
}

U0 Main()
{
    U8* question;
    question = GetStr("Ask God a question: ");

    "You asked: %s\n", question;

    U8* answer;
    answer = SpeakToGod(question);

    "God's answer: %s\n", answer;
}

Main;

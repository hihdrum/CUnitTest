void dep02(char *str)
{
  mock().actualCall("dep02")
    .withParameter("str", str);
}

void MockSet_dep02(char *str)
{
  mock().expectOneCall("dep02")
    .withParameter("str", str);
}

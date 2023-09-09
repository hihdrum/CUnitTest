int dep(void)
{
  mock().actualCall("dep");
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue)
{
  mock().expectOneCall("dep")
    .andReturnValue(iReturnValue);
}

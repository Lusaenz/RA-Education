using System.Collections.Generic;
public class RegisterResult
{
    public bool Success { get; set; }
    public string ErrorMessage { get; set; }
    public Dictionary<string, string> FieldErrors { get; set; }
    public int UserId { get; set; }

    public RegisterResult()
    {
        FieldErrors = new Dictionary<string, string>();
        UserId = -1;
    }

    public static RegisterResult SuccessResult(int userId = -1)
    {
        return new RegisterResult
        {
            Success = true,
            ErrorMessage = string.Empty,
            UserId = userId
        };
    }

    public static RegisterResult ErrorResult(string message)
    {
        return new RegisterResult
        {
            Success = false,
            ErrorMessage = message
        };
    }
}

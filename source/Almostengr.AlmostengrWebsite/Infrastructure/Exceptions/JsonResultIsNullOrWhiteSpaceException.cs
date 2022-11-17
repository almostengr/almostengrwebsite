namespace Almostengr.AlmostengrWebsite.Infrastructure.Exceptions;

internal class JsonResultIsNullOrWhiteSpaceException : Exception
{
    public JsonResultIsNullOrWhiteSpaceException()
    {
    }

    public JsonResultIsNullOrWhiteSpaceException(string? message) : base(message)
    {
    }
}
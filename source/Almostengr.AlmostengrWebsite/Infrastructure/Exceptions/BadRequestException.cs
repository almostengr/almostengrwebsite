namespace Almostengr.AlmostengrWebsite.Infrastructure.Exceptions;

internal class BadRequestException : Exception
{
    public BadRequestException()
    {
    }

    public BadRequestException(string message) : base(message)
    {
    }
}

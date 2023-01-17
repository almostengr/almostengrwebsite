using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

public abstract class AlmostengrWebsiteException : Exception
{
    protected AlmostengrWebsiteException()
    {
    }

    protected AlmostengrWebsiteException(string? message) : base(message)
    {
    }

    protected AlmostengrWebsiteException(SerializationInfo info, StreamingContext context) : base(info, context)
    {
    }

    protected AlmostengrWebsiteException(string? message, Exception? innerException) : base(message, innerException)
    {
    }
}
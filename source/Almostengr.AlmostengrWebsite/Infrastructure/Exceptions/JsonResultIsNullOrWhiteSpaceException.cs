using System.Runtime.Serialization;
using Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

namespace Almostengr.AlmostengrWebsite.Infrastructure.Exceptions;

internal class JsonResultIsNullOrWhiteSpaceException : AlmostengrWebsiteException
{
    public JsonResultIsNullOrWhiteSpaceException()
    {
    }

    public JsonResultIsNullOrWhiteSpaceException(string? message) : base(message)
    {
    }

    public JsonResultIsNullOrWhiteSpaceException(SerializationInfo info, StreamingContext context) : base(info, context)
    {
    }

    public JsonResultIsNullOrWhiteSpaceException(string? message, Exception? innerException) : base(message, innerException)
    {
    }
}
using System.Runtime.Serialization;
using Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    [Serializable]
    internal class NwsObservationIsNullException : AlmostengrWebsiteException
    {
        public NwsObservationIsNullException()
        {
        }

        public NwsObservationIsNullException(string message) : base(message)
        {
        }

        public NwsObservationIsNullException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }

        public NwsObservationIsNullException(string? message, Exception? innerException) : base(message, innerException)
        {
        }
    }
}
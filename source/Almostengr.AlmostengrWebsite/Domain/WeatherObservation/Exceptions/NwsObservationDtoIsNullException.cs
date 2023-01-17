using System.Runtime.Serialization;
using Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    [Serializable]
    internal class NwsObservationDtoIsNullException : AlmostengrWebsiteException
    {
        public NwsObservationDtoIsNullException()
        {
        }

        public NwsObservationDtoIsNullException(string message) : base(message)
        {
        }

        public NwsObservationDtoIsNullException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }

        public NwsObservationDtoIsNullException(string? message, Exception? innerException) : base(message, innerException)
        {
        }
    }
}
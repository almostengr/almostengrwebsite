using System.Runtime.Serialization;
using Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    [Serializable]
    internal class ObservationDateInvalidException : AlmostengrWebsiteException
    {
        public ObservationDateInvalidException()
        {
        }

        public ObservationDateInvalidException(string? message) : base(message)
        {
        }

        public ObservationDateInvalidException(string? message, Exception? innerException) : base(message, innerException)
        {
        }

        protected ObservationDateInvalidException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}
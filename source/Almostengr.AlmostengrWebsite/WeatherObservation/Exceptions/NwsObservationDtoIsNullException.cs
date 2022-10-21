using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.WeatherObservation
{
    [Serializable]
    internal class NwsObservationDtoIsNullException : Exception
    {
        public NwsObservationDtoIsNullException()
        {
        }

        public NwsObservationDtoIsNullException(string message) : base(message)
        {
        }

        public NwsObservationDtoIsNullException(string message, Exception? innerException) : base(message, innerException)
        {
        }

        protected NwsObservationDtoIsNullException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}